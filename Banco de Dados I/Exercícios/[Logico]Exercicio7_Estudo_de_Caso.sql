/* [Logico]Exercicio7_Estudo_de_Caso: */

CREATE TABLE Filme (
    titulo VARCHAR,
    anoLancamento INTEGER,
    idFilme INTEGER PRIMARY KEY
);

CREATE TABLE Ator_Atriz (
    codigo INTEGER PRIMARY KEY,
    nomeArtistico VARCHAR,
    sexo CHAR,
    dataNascimento DATE
);

CREATE TABLE Genero (
    idGenero INTEGER PRIMARY KEY,
    nomeGenero VARCHAR UNIQUE
);

CREATE TABLE Usuario (
    apelido VARCHAR PRIMARY KEY,
    email VARCHAR,
    senha VARCHAR,
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
    NomePersonagem VARCHAR,
    PRIMARY KEY (fk_Filme_idFilme, fk_Ator_Atriz_codigo)
);

CREATE TABLE Avaliacao (
    fk_Filme_idFilme INTEGER,
    fk_Usuario_apelido VARCHAR,
    data DATE,
    nota INTEGER,
    comentario VARCHAR,
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
    ON DELETE SET NULL;
 
ALTER TABLE Avaliacao ADD CONSTRAINT FK_Avaliacao_1
    FOREIGN KEY (fk_Filme_idFilme)
    REFERENCES Filme (idFilme)
    ON DELETE RESTRICT;
 
ALTER TABLE Avaliacao ADD CONSTRAINT FK_Avaliacao_2
    FOREIGN KEY (fk_Usuario_apelido)
    REFERENCES Usuario (apelido)
    ON DELETE RESTRICT;