CREATE DATABASE gtfs_rj;
USE gtfs_rj;

CREATE TABLE Consorcio (
    id_consorcio INTEGER PRIMARY KEY,
    nome_consorcio VARCHAR(255) UNIQUE,
    site VARCHAR(255)
);

CREATE TABLE Escala (
    id_escala VARCHAR(255) PRIMARY KEY,
    seg_sex TINYINT(1),
    sab_dom TINYINT(1)
);

CREATE TABLE Tarifa (
    id_tarifa VARCHAR(255) PRIMARY KEY,
    valor DECIMAL(10,2)
);

CREATE TABLE Linha (
    id_linha VARCHAR(255) PRIMARY KEY,
    numero_linha VARCHAR(255),
    nome_linha VARCHAR(255),
    descricao VARCHAR(255),
    tipo VARCHAR(255),
    fk_id_consorcio INTEGER,
    fk_id_tarifa VARCHAR(255)
);

CREATE TABLE Viagem (
    id_viagem VARCHAR(255) PRIMARY KEY,
    nome_destino VARCHAR(255),
    sentido TINYINT(1),
    fk_id_linha VARCHAR(255),
    fk_id_escala VARCHAR(255),
    hora_inicio TIME,
    hora_fim TIME
);

CREATE TABLE Pontos_de_Onibus (
    id_ponto VARCHAR(255) PRIMARY KEY,
    nome_ponto VARCHAR(255),
    ponto_mais_proximo VARCHAR(255),
    cod_plataforma VARCHAR(255)
);

CREATE TABLE Pontos_de_parada (
    fk_id_viagem VARCHAR(255),
    fk_id_ponto VARCHAR(255),
    sequencia INTEGER,
    PRIMARY KEY (fk_id_viagem, fk_id_ponto)
);

CREATE TABLE Tarifa_Consorcio (
    fk_id_consorcio INTEGER,
    fk_id_tarifa VARCHAR(255),
    PRIMARY KEY (fk_id_consorcio, fk_id_tarifa)
);
 
ALTER TABLE Linha ADD CONSTRAINT FK_Linha_2
    FOREIGN KEY (fk_id_consorcio)
    REFERENCES Consorcio (id_consorcio);
 
ALTER TABLE Linha ADD CONSTRAINT FK_Linha_3
    FOREIGN KEY (fk_id_tarifa)
    REFERENCES Tarifa (id_tarifa);
 
ALTER TABLE Viagem ADD CONSTRAINT FK_Viagem_2
    FOREIGN KEY (fk_id_linha)
    REFERENCES Linha (id_linha);
 
ALTER TABLE Viagem ADD CONSTRAINT FK_Viagem_3
    FOREIGN KEY (fk_id_escala)
    REFERENCES Escala (id_escala);
 
ALTER TABLE Pontos_de_parada ADD CONSTRAINT FK_Pontos_de_parada_1
    FOREIGN KEY (fk_id_viagem)
    REFERENCES Viagem (id_viagem);
 
ALTER TABLE Pontos_de_parada ADD CONSTRAINT FK_Pontos_de_parada_2
    FOREIGN KEY (fk_id_ponto)
    REFERENCES Pontos_de_Onibus (id_ponto);
 
ALTER TABLE Tarifa_Consorcio ADD CONSTRAINT FK_Tarifa_Consorcio_1
    FOREIGN KEY (fk_id_consorcio)
    REFERENCES Consorcio (id_consorcio);
 
ALTER TABLE Tarifa_Consorcio ADD CONSTRAINT FK_Tarifa_Consorcio_2
    FOREIGN KEY (fk_id_tarifa)
    REFERENCES Tarifa (id_tarifa);