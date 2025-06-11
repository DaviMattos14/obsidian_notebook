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
viagem = "D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\trips.txt"
pontos = r"D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\stops.txt"

r_consorcio = pd.read_csv(consorcio, sep=",")
#df_consorcio = r_consorcio[["agency_id", "agency_name", "agency_url"]]

r_escala= pd.read_csv(escala, sep=",")
#df_escala =r_escala[["service_id","monday","sunday"]]
#df_escala.loc[1, 'sunday'] = 1

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


