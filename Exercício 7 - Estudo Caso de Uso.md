Código SQL

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
    

---

**Query #1**

    SHOW TABLES;

| Tables_in_test |
| -------------- |
| Ator_Atriz     |
| Atuacao        |
| Avaliacao      |
| Filme          |
| Genero         |
| GeneroDoFilme  |
| Usuario        |

---
**Query #2**

    DESCRIBE Ator_Atriz;

| Field          | Type         | Null | Key | Default | Extra |
| -------------- | ------------ | ---- | --- | ------- | ----- |
| codigo         | int(11)      | NO   | PRI |         |       |
| nomeArtistico  | varchar(255) | YES  |     |         |       |
| sexo           | char(2)      | YES  |     |         |       |
| dataNascimento | date         | YES  |     |         |       |

---
**Query #3**
   
    DESCRIBE Atuacao;

| Field                | Type         | Null | Key | Default | Extra |
| -------------------- | ------------ | ---- | --- | ------- | ----- |
| fk_Filme_idFilme     | int(11)      | NO   | PRI |         |       |
| fk_Ator_Atriz_codigo | int(11)      | NO   | PRI |         |       |
| NomePersonagem       | varchar(255) | YES  |     |         |       |

---
**Query #4**
  
    DESCRIBE Avaliacao;

| Field              | Type          | Null | Key | Default | Extra |
| ------------------ | ------------- | ---- | --- | ------- | ----- |
| fk_Filme_idFilme   | int(11)       | NO   | PRI |         |       |
| fk_Usuario_apelido | varchar(255)  | NO   | PRI |         |       |
| data               | date          | YES  |     |         |       |
| nota               | decimal(10,0) | YES  |     |         |       |
| comentario         | text          | YES  |     |         |       |

---
**Query #5**

    
    DESCRIBE Filme;

| Field         | Type         | Null | Key | Default | Extra |
| ------------- | ------------ | ---- | --- | ------- | ----- |
| titulo        | varchar(255) | YES  |     |         |       |
| anoLancamento | int(11)      | YES  |     |         |       |
| idFilme       | int(11)      | NO   | PRI |         |       |

---
**Query #6**
   
    DESCRIBE Genero;

| Field      | Type         | Null | Key | Default | Extra |
| ---------- | ------------ | ---- | --- | ------- | ----- |
| idGenero   | int(11)      | NO   | PRI |         |       |
| nomeGenero | varchar(255) | YES  | UNI |         |       |

---
**Query #7**

    DESCRIBE GeneroDoFilme;

| Field              | Type    | Null | Key | Default | Extra |
| ------------------ | ------- | ---- | --- | ------- | ----- |
| fk_Filme_idFilme   | int(11) | NO   | PRI |         |       |
| fk_Genero_idGenero | int(11) | NO   | PRI |         |       |

---
**Query #8**

    DESCRIBE Usuario;

| Field   | Type         | Null | Key | Default | Extra |
| ------- | ------------ | ---- | --- | ------- | ----- |
| apelido | varchar(255) | NO   | PRI |         |       |
| email   | varchar(255) | YES  | UNI |         |       |
| senha   | varchar(255) | YES  |     |         |       |
|         |              |      |     |         |       |

---

[View on DB Fiddle](https://www.db-fiddle.com/)