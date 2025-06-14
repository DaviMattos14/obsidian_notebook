import pandas as pd
"""
Viagens
"""
viagem = r"D:\REPOSITÓRIOS\obsidian_notebook\Banco de Dados I\Projeto Final\gtfs_rio-de-janeiro\trips.txt"

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

# Converte para timedelta
df_viagem['start_time'] = pd.to_timedelta(df_viagem['start_time'])
df_viagem['end_time'] = pd.to_timedelta(df_viagem['end_time'])

# Formata como HH:MM, aplicando % 24 nas horas

df_viagem['start_time'] = df_viagem['start_time'].apply(
    lambda x: f"{x.components.hours % 24:02d}:{x.components.minutes:02d}"
    if pd.notna(x) else "00:00"
)
df_viagem['end_time'] = df_viagem['end_time'].apply(
    lambda x: f"{x.components.hours % 24:02d}:{x.components.minutes:02d}"
    if pd.notna(x) else "00:00"
)

df_viagem = df_viagem.rename(columns={
    'trip_id':"id_viagem",
    'trip_headsign':"nome_destino",
    'direction_id':"sentido",
    'route_id':"fk_id_linha",
    'service_id':"fk_id_escala",
    'start_time':"hora_inicio", 
    'end_time':"hora_fim"
})

print(df_viagem.head(50))
