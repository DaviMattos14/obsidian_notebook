import pandas as pd

file_path = r'D:\REPOSITÓRIOS\obsidian_notebook\Computação Científica e Análise de Dados\Trabalho Final\dataset.csv'
df_musicas = pd.read_csv(file_path, sep=',')

print(df_musicas)