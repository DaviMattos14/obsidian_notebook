import pandas as pd
import mysql.connector
from mysql.connector import Error
import datetime as data

def connect_mysql():
    """
    Função para conectar ao banco de dados MySQL e executar uma consulta de teste.
    """
    connection = None  
    try:
        connection = mysql.connector.connect(
            host='localhost',       
            user='Admin',     
            password='1310223a8',
            database='filmes'    
        )
        if connection.is_connected():
            print("Conexão com o MySQL bem-sucedida!")
    except Error as e:
        print(f"Erro ao conectar com o MySQL: {e}")
    return connection

def execute_query(connection, query):
    """
    Função para executar uma query (INSERT, ALTER TABLE) no banco de dados MySQL.
    """
    cursor = connection.cursor()
    try:
        cursor.execute(query)
        connection.commit()
        print("Query successful")
    except Error as err:
        print(f"Error: '{err}'")

def read_query(connection, query):
    """
    Função para ler uma query (SELECT) no banco de dados MySQL.
    """
    cursor = connection.cursor()
    result = None
    try:
        cursor.execute(query)
        result = cursor.fetchall()
        return result
    except Error as err:
        print(f"Error: '{err}'")

"""
connect = connect_mysql()
data = data.datetime(1964,6,15)
query = f"""
(1, "Kid Bengala", "H", '1964-06-15')
"""
execute_query(connect, query)
connect.close()
"""

consorcio = r"D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\agency.txt"
escala = r"D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\calendar.txt"
linha = r"D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\routes.txt"
pontos_de_onibus = r"D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\stops.txt"
pontos_de_parada = r"D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\stop_times.txt"
tarifa = r"D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\fare_attributes.txt"
tarifa_linha = r"D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\fare_rules.txt"
viagem = r"D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\trips.txt"
pontos = r"D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\stops.txt"

"""
Consorcio
"""
r_consorcio = pd.read_csv(consorcio, sep=",")
df_consorcio = r_consorcio[["agency_id", "agency_name", "agency_url"]]

"""
Escala
"""
r_escala= pd.read_csv(escala, sep=",")
df_escala =r_escala[["service_id","monday","sunday"]]
df_escala.loc[1, 'sunday'] = 1

"""
Linhas
"""
r_linha = pd.read_csv(linha, sep=",")
r_linha = r_linha[["route_id", "route_short_name", "route_long_name","route_desc", "route_type","agency_id","fare_id"]]
r_tarifa_linha = pd.read_csv(tarifa_linha, sep=",")
r_tarifa_linha = r_tarifa_linha[["fare_id","route_id"]]
df_linha = pd.merge(
    r_linha,
    r_tarifa_linha,
    on='route_id',
    how='left',
    suffixes=('_antiga', '_nova') # Adiciona sufixos para diferenciar as colunas 'tarifa'
)
df_linha = df_linha.drop('fare_id_antiga', axis=1)
df_linha = df_linha.rename(columns={'fare_id_nova': 'fare_id'})

df_itineraries = pd.read_csv('D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\itinerario.csv', sep=",")
df_itineraries['servico'] = df_itineraries['servico'].astype(str)
route_type_map = df_itineraries[['servico', 'tipo_rota']].drop_duplicates().set_index('servico')

df_linha['route_short_name'] = df_linha['route_short_name'].astype(str)
df_merged = pd.merge(
    df_linha,
    route_type_map,
    left_on='route_short_name',
    right_index=True,
    how='left'
)
df_merged['route_type'] = df_merged['tipo_rota'].fillna(df_merged['route_type'])
df_linha = df_merged.drop(columns=['tipo_rota'])

"""
Pontos de Ônibus
"""
df_pontos_BUS = pd.read_csv(pontos_de_onibus, sep=",")
df_pontos_BUS = df_pontos_BUS[["stop_id","stop_name","parent_station","platform_code"]]

"""
Pontos de Parada na Viagem
"""
df_Ponto_Parada = pd.read_csv(pontos_de_parada, sep=",")
df_Ponto_Parada = df_Ponto_Parada[["trip_id","stop_id","stop_sequence"]]

"""
Tarifa
"""
df_tarifa = pd.read_csv(tarifa, sep=",")
df_tarifa1 = df_tarifa[["fare_id","price"]]

"""
Tarifa Consorcio
"""
df_tarifa_consorcio = df_tarifa[["agency_id","fare_id"]]

"""
Viagens
"""
df_viagem = pd.read_csv(viagem,sep=",")
df_viagem = df_viagem[["trip_id","trip_headsign","direction_id","route_id","service_id"]]
df_frequencia = pd.read_csv(r'D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\frequencies.txt',sep=",")
df_frequencia = df_frequencia[['trip_id', 'start_time', 'end_time']]

df_viagem = pd.merge(
    df_viagem,
    df_frequencia,
    on='trip_id',  # A coluna comum que serve como chave
    how='left'     # 'left' mantém todos os dados de df_trips
)

df_viagem['start_time'] = pd.to_timedelta(df_viagem['start_time'], errors='coerce')
df_viagem['end_time'] = pd.to_timedelta(df_viagem['end_time'], errors='coerce')

def formatar_para_hhmmss(td):
    """
    Formata um objeto timedelta para uma string no formato HH:MM:SS.
    Lida corretamente com durações maiores que 24 horas.
    """
    if pd.isnull(td):
        return None  # Retorna None se o valor for NaT (Not a Time)
    
    # Calcula o total de segundos e, a partir dele, as horas, minutos e segundos
    total_seconds = int(td.total_seconds())
    horas = total_seconds // 3600
    minutos = (total_seconds % 3600) // 60
    segundos = total_seconds % 60
    
    # Retorna a string formatada com preenchimento de zero
    return f"{horas:02d}:{minutos:02d}:{segundos:02d}"

# Aplica a função de formatação às colunas de tempo
df_viagem['start_time'] = df_viagem['start_time'].apply(formatar_para_hhmmss)
df_viagem['end_time'] = df_viagem['end_time'].apply(formatar_para_hhmmss)

print(df_viagem.head(20))