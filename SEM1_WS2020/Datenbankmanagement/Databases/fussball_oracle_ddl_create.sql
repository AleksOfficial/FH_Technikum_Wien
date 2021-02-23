--------------------------------------------------------
--  Create Database FUSSBALLBASE
--------------------------------------------------------

--------------------------------------------------------
--  Create Tables
--------------------------------------------------------

--------------------------------------------------------
--  DDL for Table BESTELLUNGEN
--------------------------------------------------------

  CREATE TABLE "BESTELLUNGEN" 
   (	"BESTELL_ID" NUMBER, 
	"PERSONEN_ID" NUMBER(9,0), 
	"SPIEL_ID" NUMBER(9,0), 
	"ANZAHL_GEWUENSCHTER_KARTEN" NUMBER, 
	"ANZAHL_RESERVIERTER_KARTEN" NUMBER, 
	"MAX_PREISKATEGORIE" NUMBER
   ) ;
--------------------------------------------------------
--  DDL for Table KARTEN
--------------------------------------------------------

  CREATE TABLE "KARTEN" 
   (	"KARTEN_ID" NUMBER, 
	"SITZPLATZNR" NUMBER, 
	"PREISKATEGORIE" NUMBER, 
	"SPIEL_ID" NUMBER(9,0), 
	"BESTELL_ID" NUMBER, 
	"PERSONEN_ID" NUMBER(9,0)
   ) ;
--------------------------------------------------------
--  DDL for Table KLEIN
--------------------------------------------------------

  CREATE TABLE "KLEIN" 
   (	"K" NUMBER
   ) ;
--------------------------------------------------------
--  DDL for Table NATION
--------------------------------------------------------

  CREATE TABLE "NATION" 
   (	"NATIONNAME" VARCHAR2(20), 
	"TRAINERNAME" VARCHAR2(100), 
	"GRUPPE" VARCHAR2(50)
   ) ;
--------------------------------------------------------
--  DDL for Table PERSONEN
--------------------------------------------------------

  CREATE TABLE "PERSONEN" 
   (	"PERSONEN_ID" NUMBER(9,0), 
	"NACHNAME" VARCHAR2(30), 
	"VORNAME" VARCHAR2(20), 
	"GEB_DATUM" DATE, 
	"PLZ" NUMBER(5,0), 
	"WOHNORT" VARCHAR2(20), 
	"STRASSE" VARCHAR2(20), 
	"LAND" CHAR(18), 
	"AUSWEISNUMMER" VARCHAR2(20), 
	"KREDITKARTENNUMMER" CHAR(18), 
	"BLZ" CHAR(18), 
	"KONTONUMMER" CHAR(18)
   ) ;
--------------------------------------------------------
--  DDL for Table PREISKATEGORIE
--------------------------------------------------------

  CREATE TABLE "PREISKATEGORIE" 
   (	"PREISKATEGORIE" NUMBER, 
	"PREIS" NUMBER
   ) ;
--------------------------------------------------------
--  DDL for Table SPIELE
--------------------------------------------------------

  CREATE TABLE "SPIELE" 
   (	"SPIEL_ID" NUMBER(9,0), 
	"MANNSCHAFT_1" VARCHAR2(20), 
	"MANNSCHAFT_2" VARCHAR2(20), 
	"AUSFUEHRUNGSORT" CHAR(18), 
	"SPIELTAG" NUMBER(2,0), 
	"TERMIN" DATE, 
	"TYP" VARCHAR2(20), 
	"ERGEBNIS" VARCHAR2(5), 
	"ANZAHL_ROTE_KARTEN" NUMBER(2,0), 
	"ANZAHL_GELBE_KARTEN" NUMBER(2,0), 
	"ANZAHL_ZUSCHAUER" NUMBER(6,0)
   ) ;
--------------------------------------------------------
--  DDL for Table SPIELER
--------------------------------------------------------

  CREATE TABLE "SPIELER" 
   (	"SPIELER_ID" NUMBER(9,0), 
	"NATIONNAME" VARCHAR2(20), 
	"NACHNAME" VARCHAR2(30), 
	"VORNAME" VARCHAR2(20), 
	"FUNKTION" VARCHAR2(20), 
	"GEB_DATUM" DATE, 
	"PLZ" NUMBER(5,0), 
	"WOHNORT" VARCHAR2(20), 
	"STRASSE" VARCHAR2(20), 
	"LAND" VARCHAR2(20), 
	"GEHALT_IN_EURO" NUMBER(8,2)
   ) ;
--------------------------------------------------------
--  DDL for Table TORE
--------------------------------------------------------

  CREATE TABLE "TORE" 
   (	"MINUTE" NUMBER(3,0), 
	"SPIEL_ID" NUMBER(3,0), 
	"SPIELER_ID" NUMBER(9,0)
   ) ;



--------------------------------------------------------
--  Create Indexes
--------------------------------------------------------

--------------------------------------------------------
--  DDL for Index SYS_C001135836
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135836" ON "TORE" ("SPIEL_ID", "SPIELER_ID", "MINUTE") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135837
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135837" ON "KARTEN" ("KARTEN_ID") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135838
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135838" ON "BESTELLUNGEN" ("BESTELL_ID") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135839
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135839" ON "SPIELE" ("SPIEL_ID") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135840
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135840" ON "SPIELER" ("SPIELER_ID") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135841
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135841" ON "NATION" ("NATIONNAME") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135842
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135842" ON "PREISKATEGORIE" ("PREISKATEGORIE") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135843
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135843" ON "PERSONEN" ("PERSONEN_ID") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135844
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135844" ON "NATION" ("TRAINERNAME") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135845
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135845" ON "SPIELER" ("NACHNAME", "VORNAME", "GEB_DATUM") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135846
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135846" ON "KARTEN" ("SITZPLATZNR", "SPIEL_ID") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135847
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135847" ON "PERSONEN" ("NACHNAME", "VORNAME", "GEB_DATUM", "PLZ") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135848
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135848" ON "PERSONEN" ("AUSWEISNUMMER") 
  ;
--------------------------------------------------------
--  DDL for Index SYS_C001135849
--------------------------------------------------------

  CREATE UNIQUE INDEX "SYS_C001135849" ON "BESTELLUNGEN" ("PERSONEN_ID", "SPIEL_ID") 
  ;
--------------------------------------------------------
--  DDL for Index XIF1KARTEN
--------------------------------------------------------

  CREATE INDEX "XIF1KARTEN" ON "KARTEN" ("SITZPLATZNR") 
  ;
--------------------------------------------------------
--  DDL for Index XIF1SPIELER
--------------------------------------------------------

  CREATE INDEX "XIF1SPIELER" ON "SPIELER" ("VORNAME", "NACHNAME") 
  ;


--------------------------------------------------------
--  Add Constraints
--------------------------------------------------------

--------------------------------------------------------
--  Constraints for Table BESTELLUNGEN
--------------------------------------------------------

  ALTER TABLE "BESTELLUNGEN" ADD CONSTRAINT "KARTENANZAHL_IB" CHECK (Anzahl_Gewuenschter_Karten >= Anzahl_Reservierter_Karten) DEFERRABLE INITIALLY DEFERRED ENABLE;
 
  ALTER TABLE "BESTELLUNGEN" MODIFY ("BESTELL_ID" NOT NULL ENABLE);
 
  ALTER TABLE "BESTELLUNGEN" MODIFY ("PERSONEN_ID" NOT NULL ENABLE);
 
  ALTER TABLE "BESTELLUNGEN" MODIFY ("SPIEL_ID" NOT NULL ENABLE);
 
  ALTER TABLE "BESTELLUNGEN" MODIFY ("MAX_PREISKATEGORIE" NOT NULL ENABLE);
 
  ALTER TABLE "BESTELLUNGEN" ADD PRIMARY KEY ("BESTELL_ID") ENABLE;
 
  ALTER TABLE "BESTELLUNGEN" ADD UNIQUE ("PERSONEN_ID", "SPIEL_ID") ENABLE;
--------------------------------------------------------
--  Constraints for Table KARTEN
--------------------------------------------------------

  ALTER TABLE "KARTEN" MODIFY ("KARTEN_ID" NOT NULL ENABLE);
 
  ALTER TABLE "KARTEN" MODIFY ("PREISKATEGORIE" NOT NULL ENABLE);
 
  ALTER TABLE "KARTEN" MODIFY ("SPIEL_ID" NOT NULL ENABLE);
 
  ALTER TABLE "KARTEN" ADD PRIMARY KEY ("KARTEN_ID") ENABLE;
 
  ALTER TABLE "KARTEN" ADD UNIQUE ("SITZPLATZNR", "SPIEL_ID") ENABLE;
--------------------------------------------------------
--  Constraints for Table NATION
--------------------------------------------------------

  ALTER TABLE "NATION" MODIFY ("NATIONNAME" NOT NULL ENABLE);
 
  ALTER TABLE "NATION" MODIFY ("TRAINERNAME" NOT NULL ENABLE);
 
  ALTER TABLE "NATION" ADD PRIMARY KEY ("NATIONNAME") ENABLE;
 
  ALTER TABLE "NATION" ADD UNIQUE ("TRAINERNAME") ENABLE;
--------------------------------------------------------
--  Constraints for Table PERSONEN
--------------------------------------------------------

  ALTER TABLE "PERSONEN" ADD CONSTRAINT "AUSWEISPFLICHT_IB" CHECK (Ausweisnummer IS NOT NULL AND LENGTH(Ausweisnummer) >= 7) ENABLE;
 
  ALTER TABLE "PERSONEN" ADD CONSTRAINT "BANKVERBINDUNG_IB" CHECK ( (BLZ IS NOT NULL AND Kontonummer IS NOT NULL) OR (BLZ IS NULL AND Kontonummer IS NULL) ) DEFERRABLE INITIALLY DEFERRED ENABLE;
 
  ALTER TABLE "PERSONEN" MODIFY ("PERSONEN_ID" NOT NULL ENABLE);
 
  ALTER TABLE "PERSONEN" MODIFY ("NACHNAME" NOT NULL ENABLE);
 
  ALTER TABLE "PERSONEN" MODIFY ("VORNAME" NOT NULL ENABLE);
 
  ALTER TABLE "PERSONEN" MODIFY ("GEB_DATUM" NOT NULL ENABLE);
 
  ALTER TABLE "PERSONEN" MODIFY ("PLZ" NOT NULL ENABLE);
 
  ALTER TABLE "PERSONEN" MODIFY ("WOHNORT" NOT NULL ENABLE);
 
  ALTER TABLE "PERSONEN" ADD PRIMARY KEY ("PERSONEN_ID") ENABLE;
 
  ALTER TABLE "PERSONEN" ADD UNIQUE ("NACHNAME", "VORNAME", "GEB_DATUM", "PLZ") ENABLE;
 
  ALTER TABLE "PERSONEN" ADD UNIQUE ("AUSWEISNUMMER") ENABLE;
--------------------------------------------------------
--  Constraints for Table PREISKATEGORIE
--------------------------------------------------------

  ALTER TABLE "PREISKATEGORIE" MODIFY ("PREISKATEGORIE" NOT NULL ENABLE);
 
  ALTER TABLE "PREISKATEGORIE" ADD PRIMARY KEY ("PREISKATEGORIE") ENABLE;
--------------------------------------------------------
--  Constraints for Table SPIELE
--------------------------------------------------------

  ALTER TABLE "SPIELE" ADD CONSTRAINT "GEGNER_IB" CHECK (Mannschaft_1 <> Mannschaft_2) ENABLE;
 
  ALTER TABLE "SPIELE" MODIFY ("SPIEL_ID" NOT NULL ENABLE);
 
  ALTER TABLE "SPIELE" MODIFY ("MANNSCHAFT_1" NOT NULL ENABLE);
 
  ALTER TABLE "SPIELE" MODIFY ("MANNSCHAFT_2" NOT NULL ENABLE);
 
  ALTER TABLE "SPIELE" ADD PRIMARY KEY ("SPIEL_ID") ENABLE;
--------------------------------------------------------
--  Constraints for Table SPIELER
--------------------------------------------------------

  ALTER TABLE "SPIELER" MODIFY ("SPIELER_ID" NOT NULL ENABLE);
 
  ALTER TABLE "SPIELER" MODIFY ("NATIONNAME" NOT NULL ENABLE);
 
  ALTER TABLE "SPIELER" MODIFY ("NACHNAME" NOT NULL ENABLE);
 
  ALTER TABLE "SPIELER" MODIFY ("VORNAME" NOT NULL ENABLE);
 
  ALTER TABLE "SPIELER" ADD PRIMARY KEY ("SPIELER_ID") ENABLE;
 
  ALTER TABLE "SPIELER" ADD UNIQUE ("NACHNAME", "VORNAME", "GEB_DATUM") ENABLE;
--------------------------------------------------------
--  Constraints for Table TORE
--------------------------------------------------------

  ALTER TABLE "TORE" MODIFY ("MINUTE" NOT NULL ENABLE);
 
  ALTER TABLE "TORE" MODIFY ("SPIEL_ID" NOT NULL ENABLE);
 
  ALTER TABLE "TORE" MODIFY ("SPIELER_ID" NOT NULL ENABLE);
 
  ALTER TABLE "TORE" ADD PRIMARY KEY ("SPIEL_ID", "SPIELER_ID", "MINUTE") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table BESTELLUNGEN
--------------------------------------------------------

  ALTER TABLE "BESTELLUNGEN" ADD FOREIGN KEY ("PERSONEN_ID")
	  REFERENCES "PERSONEN" ("PERSONEN_ID") ENABLE;
 
  ALTER TABLE "BESTELLUNGEN" ADD FOREIGN KEY ("MAX_PREISKATEGORIE")
	  REFERENCES "PREISKATEGORIE" ("PREISKATEGORIE") ENABLE;
 
  ALTER TABLE "BESTELLUNGEN" ADD FOREIGN KEY ("SPIEL_ID")
	  REFERENCES "SPIELE" ("SPIEL_ID") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table KARTEN
--------------------------------------------------------

  ALTER TABLE "KARTEN" ADD FOREIGN KEY ("PERSONEN_ID")
	  REFERENCES "PERSONEN" ("PERSONEN_ID") ON DELETE SET NULL ENABLE;
 
  ALTER TABLE "KARTEN" ADD FOREIGN KEY ("BESTELL_ID")
	  REFERENCES "BESTELLUNGEN" ("BESTELL_ID") ON DELETE SET NULL ENABLE;
 
  ALTER TABLE "KARTEN" ADD FOREIGN KEY ("SPIEL_ID")
	  REFERENCES "SPIELE" ("SPIEL_ID") ENABLE;
 
  ALTER TABLE "KARTEN" ADD FOREIGN KEY ("PREISKATEGORIE")
	  REFERENCES "PREISKATEGORIE" ("PREISKATEGORIE") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table SPIELE
--------------------------------------------------------

  ALTER TABLE "SPIELE" ADD FOREIGN KEY ("MANNSCHAFT_2")
	  REFERENCES "NATION" ("NATIONNAME") ENABLE;
 
  ALTER TABLE "SPIELE" ADD FOREIGN KEY ("MANNSCHAFT_1")
	  REFERENCES "NATION" ("NATIONNAME") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table SPIELER
--------------------------------------------------------

  ALTER TABLE "SPIELER" ADD FOREIGN KEY ("NATIONNAME")
	  REFERENCES "NATION" ("NATIONNAME") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table TORE
--------------------------------------------------------

  ALTER TABLE "TORE" ADD FOREIGN KEY ("SPIEL_ID")
	  REFERENCES "SPIELE" ("SPIEL_ID") ENABLE;
 
  ALTER TABLE "TORE" ADD FOREIGN KEY ("SPIELER_ID")
	  REFERENCES "SPIELER" ("SPIELER_ID") ENABLE;
