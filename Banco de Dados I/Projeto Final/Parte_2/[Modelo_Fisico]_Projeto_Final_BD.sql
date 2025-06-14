/* [Modelo_Lógico]_Projeto_Final_BD: */

CREATE TABLE Consorcio (
    id_consorcio INTEGER PRIMARY KEY,
    nome_consorcio VARCHAR UNIQUE,
    site VARCHAR
);

CREATE TABLE Escala (
    id_escala VARCHAR PRIMARY KEY,
    sab_dom BOOLEAN,
    seg_sex BOOLEAN
);

CREATE TABLE Tarifa (
    id_tarifa VARCHAR PRIMARY KEY,
    valor DECIMAL
);

CREATE TABLE Linha (
    id_linha VARCHAR PRIMARY KEY,
    numero_linha VARCHAR,
    nome_linha VARCHAR,
    descricao VARCHAR,
    tipo VARCHAR,
    fk_Consorcio_id_consorcio INTEGER,
    fk_Tarifa_id_tarifa VARCHAR
);

CREATE TABLE Viagem (
    id_viagem VARCHAR PRIMARY KEY,
    nome_destino VARCHAR,
    sentido BOOLEAN,
    fk_Linha_id_linha VARCHAR,
    fk_Escala_id_escala VARCHAR,
    hora_fim TIME,
    hora_inicio TIME
);

CREATE TABLE Pontos_de_Onibus (
    id_ponto VARCHAR PRIMARY KEY,
    nome_ponto VARCHAR,
    ponto_mais_proximo VARCHAR,
    cod_plataforma VARCHAR
);

CREATE TABLE Pontos_de_parada (
    fk_Viagem_id_viagem VARCHAR,
    fk_Pontos_de_Onibus_id_ponto VARCHAR,
    sequencia INTEGER,
    PRIMARY KEY (fk_Viagem_id_viagem, fk_Pontos_de_Onibus_id_ponto)
);

CREATE TABLE Tarifa_Consorcio (
    fk_Consorcio_id_consorcio INTEGER,
    fk_Tarifa_id_tarifa VARCHAR,
    PRIMARY KEY (fk_Consorcio_id_consorcio, fk_Tarifa_id_tarifa)
);
 
ALTER TABLE Linha ADD CONSTRAINT FK_Linha_2
    FOREIGN KEY (fk_Consorcio_id_consorcio)
    REFERENCES Consorcio (id_consorcio)
    ON DELETE RESTRICT;
 
ALTER TABLE Linha ADD CONSTRAINT FK_Linha_3
    FOREIGN KEY (fk_Tarifa_id_tarifa)
    REFERENCES Tarifa (id_tarifa)
    ON DELETE RESTRICT;
 
ALTER TABLE Viagem ADD CONSTRAINT FK_Viagem_2
    FOREIGN KEY (fk_Linha_id_linha)
    REFERENCES Linha (id_linha)
    ON DELETE RESTRICT;
 
ALTER TABLE Viagem ADD CONSTRAINT FK_Viagem_3
    FOREIGN KEY (fk_Escala_id_escala)
    REFERENCES Escala (id_escala)
    ON DELETE RESTRICT;
 
ALTER TABLE Pontos_de_parada ADD CONSTRAINT FK_Pontos_de_parada_1
    FOREIGN KEY (fk_Viagem_id_viagem)
    REFERENCES Viagem (id_viagem)
    ON DELETE RESTRICT;
 
ALTER TABLE Pontos_de_parada ADD CONSTRAINT FK_Pontos_de_parada_2
    FOREIGN KEY (fk_Pontos_de_Onibus_id_ponto)
    REFERENCES Pontos_de_Onibus (id_ponto)
    ON DELETE RESTRICT;
 
ALTER TABLE Tarifa_Consorcio ADD CONSTRAINT FK_Tarifa_Consorcio_1
    FOREIGN KEY (fk_Consorcio_id_consorcio)
    REFERENCES Consorcio (id_consorcio)
    ON DELETE RESTRICT;
 
ALTER TABLE Tarifa_Consorcio ADD CONSTRAINT FK_Tarifa_Consorcio_2
    FOREIGN KEY (fk_Tarifa_id_tarifa)
    REFERENCES Tarifa (id_tarifa)
    ON DELETE RESTRICT;