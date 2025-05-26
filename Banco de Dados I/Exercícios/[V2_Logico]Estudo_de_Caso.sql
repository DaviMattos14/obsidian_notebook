CREATE TABLE Filme (
    titulo VARCHAR(255),
    anoLancamento INTEGER,
    idFilme INTEGER PRIMARY KEY,
    fk_genero_genero_PK INTEGER
);

CREATE TABLE Ator_Atriz (
    codigo INTEGER PRIMARY KEY,
    nomeArtistico VARCHAR(255),
    sexo CHAR(2),
    dataNascimento DATE
);

CREATE TABLE Usuario (
    apelido VARCHAR(255)PRIMARY KEY,
    email VARCHAR(255) UNIQUE,
    senha VARCHAR(255)
);

CREATE TABLE genero (
    genero_PK INTEGER PRIMARY KEY,
    genero VARCHAR(255) UNIQUE
);

CREATE TABLE Atuacao (
    fk_Filme_idFilme INTEGER,
    fk_Ator_Atriz_codigo INTEGER,
    NomePersonagem VARCHAR(255),
    PRIMARY KEY (fk_Ator_Atriz_codigo, fk_Filme_idFilme)
);

CREATE TABLE Avaliacao (
    fk_Filme_idFilme INTEGER,
    fk_Usuario_apelido VARCHAR(255),
    data DATE,
    nota DECIMAL,
    comentario VARCHAR(255),
    PRIMARY KEY (fk_Filme_idFilme,fk_Usuario_apelido)
);
 
ALTER TABLE Filme ADD CONSTRAINT FK_Filme_2
    FOREIGN KEY (fk_genero_genero_PK)
    REFERENCES genero (genero_PK);
 
ALTER TABLE Atuacao ADD CONSTRAINT FK_Atuacao_1
    FOREIGN KEY (fk_Filme_idFilme)
    REFERENCES Filme (idFilme)
    ON DELETE RESTRICT;
 
ALTER TABLE Atuacao ADD CONSTRAINT FK_Atuacao_2
    FOREIGN KEY (fk_Ator_Atriz_codigo)
    REFERENCES Ator_Atriz (codigo)
;
 
ALTER TABLE Avaliacao ADD CONSTRAINT FK_Avaliacao_1
    FOREIGN KEY (fk_Filme_idFilme)
    REFERENCES Filme (idFilme)
;
 
ALTER TABLE Avaliacao ADD CONSTRAINT FK_Avaliacao_2
    FOREIGN KEY (fk_Usuario_apelido)
    REFERENCES Usuario (apelido)
    ON DELETE CASCADE;