--USE WT_YourName

DROP TABLE IF EXISTS MEMBERSHIP;
DROP TABLE IF EXISTS PLAYER;
DROP TABLE IF EXISTS TEAM;

CREATE TABLE PLAYER (
PLAYER_ID INTEGER IDENTITY PRIMARY KEY,
PLAYER_FNAME VARCHAR(25) NOT NULL,
PLAYER_LNAME VARCHAR(25) NOT NULL
);

CREATE TABLE TEAM (
TEAM_CODE CHAR(3) PRIMARY KEY,
TEAM_NAME VARCHAR(25) NOT NULL,
FIGHT_SONG VARCHAR(25)
);

CREATE TABLE MEMBERSHIP (
PLAYER_ID INTEGER NOT NULL,
TEAM_CODE CHAR(3) NOT NULL,
PRIMARY KEY (PLAYER_ID, TEAM_CODE),
FOREIGN KEY (PLAYER_ID) REFERENCES PLAYER (PLAYER_ID) ON DELETE CASCADE,
FOREIGN KEY (TEAM_CODE) REFERENCES TEAM (TEAM_CODE) ON DELETE CASCADE
);

INSERT INTO PLAYER VALUES ('Richard','Sherman');
INSERT INTO PLAYER VALUES ('Tony', 'Romo');
INSERT INTO PLAYER VALUES ('Brett', 'Hundley');
INSERT INTO PLAYER VALUES ('Russell', 'Wilson');
INSERT INTO PLAYER VALUES ('Amar', 'Lilo');

INSERT INTO TEAM (TEAM_CODE, TEAM_NAME, FIGHT_SONG)
            VALUES ('GB', 'Green Bay Packers', 'Go! You Packers Go!'); 
INSERT INTO TEAM (TEAM_CODE, TEAM_NAME, FIGHT_SONG)
            VALUES ('SEA', 'Seattle Seahawks', 'Power Thru');
INSERT INTO TEAM (TEAM_CODE, TEAM_NAME, FIGHT_SONG)
            VALUES ('DAL', 'Dallas Cowboys', 'Cowboys Stampede March');
INSERT INTO TEAM (TEAM_CODE, TEAM_NAME, FIGHT_SONG)
		    VALUES ('AMA', 'Amarillian', 'Keep Amarillo Yellow');

INSERT INTO MEMBERSHIP (PLAYER_ID, TEAM_CODE) VALUES (3, 'GB');
INSERT INTO MEMBERSHIP (PLAYER_ID, TEAM_CODE) VALUES (1, 'SEA');
INSERT INTO MEMBERSHIP (PLAYER_ID, TEAM_CODE) VALUES (2, 'DAL');
INSERT INTO MEMBERSHIP (PLAYER_ID, TEAM_CODE) VALUES (4, 'SEA');

