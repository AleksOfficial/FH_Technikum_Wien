CREATE TABLE adressen(
  addr_id INT PRIMARY KEY,
  strasse VARCHAR(50) NOT NULL,
  plz number(5) NOT NULL,
  hausnummer NUMBER,

);

CREATE TABLE personen(
  pers_id INT PRIMARY KEY,
  vorname VARCHAR(50),
  nachname VARCHAR(50),
  geschlecht VARCHAR(1) CHECK(geschlecht in('W','M'))
);

CREATE TABLE kunden(
  kundennummer INT NOT NULL,
  pers_id int NOT NULL,
  PRIMARY KEY(pers_id),
  FOREIGN KEY(pers_id) REFERENCES personen(pers_id)
);

CREATE TABLE mitarbeiter(
  mitarbeiternummer INT NOT NULL,
  svn NUMBER NOT NULL,
  geburtsdatum DATE NOT NULL,
  eintrittsdatum DATE NOT NULL,
  austrittsdatum DATE NULL,
  pers_id int NOT NULL,
  PRIMARY KEY(pers_id),
  FOREIGN KEY(pers_id) REFERENCES personen(pers_id)
);

CREATE TABLE allergene(
  kuerzel VARCHAR(1) PRIMARY KEY,
  bezeichnung VARCHAR(50) NOT NULL,
);

CREATE TABLE produkte(
	produkt_id NUMBER PRIMARY KEY NOT NULL,
	name VARCHAR2(20) NOT NULL,
	preis NUMBER,
	mwst NUMBER,
	ausgelaufen INT(1) CHECK(ausgelaufen BETWEEN 0 AND 1)
);

CREATE TABLE rechnungen(
	rechn_nr NUMBER PRIMARY KEY NOT NULL,
	datum DATE NOT NULL,
	uhrzeit NUMBER
);

CREATE TABLE filialen(
	f_id NUMBER PRIMARY KEY NOT NULL,
	"uid" NUMBER UNIQUE NOT NULL,
	name VARCHAR2(30) NOT NULL,
	telefon NUMBER, 
	fax NUMBER,
	geschlossen INT CHECK(INT BETWEEN 0 and 1)
);


