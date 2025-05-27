CREATE TABLE Filme (
    titulo VARCHAR(255),
    anoLancamento INTEGER,
    idFilme INTEGER PRIMARY KEY
);

CREATE TABLE Ator_Atriz (
    codigo INTEGER PRIMARY KEY,
    nomeArtistico VARCHAR(255),
    sexo CHAR(2),
    dataNascimento DATE
);

CREATE TABLE Genero (
    idGenero INTEGER PRIMARY KEY,
    nomeGenero VARCHAR(255) UNIQUE
);

CREATE TABLE Usuario (
    apelido VARCHAR(255) PRIMARY KEY,
    email VARCHAR(255)UNIQUE,
    senha VARCHAR(255),
    UNIQUE (email, apelido)
);

CREATE TABLE GeneroDoFilme (
    fk_Filme_idFilme INTEGER,
    fk_Genero_idGenero INTEGER,
    PRIMARY KEY (fk_Genero_idGenero, fk_Filme_idFilme)
);

CREATE TABLE Atuacao (
    fk_Filme_idFilme INTEGER,
    fk_Ator_Atriz_codigo INTEGER,
    NomePersonagem VARCHAR(255),
    PRIMARY KEY (fk_Filme_idFilme, fk_Ator_Atriz_codigo)
);

CREATE TABLE Avaliacao (
    fk_Filme_idFilme INTEGER,
    fk_Usuario_apelido VARCHAR(255),
    data DATE,
    nota DECIMAL,
    comentario TEXT,
    PRIMARY KEY (fk_Usuario_apelido, fk_Filme_idFilme)
);
 
ALTER TABLE GeneroDoFilme ADD CONSTRAINT FK_GeneroDoFilme_1
    FOREIGN KEY (fk_Filme_idFilme)
    REFERENCES Filme (idFilme)
    ON DELETE RESTRICT;
 
ALTER TABLE GeneroDoFilme ADD CONSTRAINT FK_GeneroDoFilme_2
    FOREIGN KEY (fk_Genero_idGenero)
    REFERENCES Genero (idGenero)
    ON DELETE RESTRICT;
 
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
    ON DELETE RESTRICT;
 
ALTER TABLE Avaliacao ADD CONSTRAINT FK_Avaliacao_2
    FOREIGN KEY (fk_Usuario_apelido)
    REFERENCES Usuario (apelido)
;

SHOW TABLES;
DESCRIBE ator_atriz;
DESCRIBE atuacao;
DESCRIBE avaliacao;
DESCRIBE filme;
DESCRIBE genero;
DESCRIBE generodofilme;
DESCRIBE usuario;