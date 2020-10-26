--------------------------------------------------------
--  CREATE Fahrrad DB
--------------------------------------------------------

--------------------------------------------------------
--  DDL for Sequence LIEFER_NR
--------------------------------------------------------

   CREATE SEQUENCE  "LIEFER_NR"  MINVALUE 1 MAXVALUE 999999999999999999999999999 INCREMENT BY 1 START WITH 1 CACHE 20 NOORDER  NOCYCLE ;
--------------------------------------------------------
--  DDL for Table ABTEILUNGEN
--------------------------------------------------------

  CREATE TABLE "ABTEILUNGEN" 
   (	"ABT_NR" NUMBER(38,0), 
	"LEITER" NUMBER(38,0), 
	"NAME" VARCHAR2(50), 
	"ORT" VARCHAR2(50)
   ) ;
--------------------------------------------------------
--  DDL for Table ANGESTELLTE
--------------------------------------------------------

  CREATE TABLE "ANGESTELLTE" 
   (	"ANG_NR" NUMBER(38,0), 
	"ABT_NR" NUMBER(38,0), 
	"AUFGABENBESCHREIBUNG" VARCHAR2(50), 
	"BERUF" VARCHAR2(50), 
	"NACHNAME" VARCHAR2(50), 
	"VORNAME" VARCHAR2(50), 
	"GESCHLECHT" CHAR(1), 
	"EINTRITTSDATUM" DATE, 
	"GEHALT" NUMBER(9,2) DEFAULT 0, 
	"ABZUEGE" NUMBER(9,2) DEFAULT 0, 
	"ORT" VARCHAR2(50), 
	"STRASSE" VARCHAR2(50), 
	"ZEITSTEMPEL" DATE
   ) ;
--------------------------------------------------------
--  DDL for Table ARTIKEL
--------------------------------------------------------

  CREATE TABLE "ARTIKEL" 
   (	"TNR" NUMBER(38,0), 
	"BEZEICHNUNG" VARCHAR2(50), 
	"ARTIKEL_TYP" VARCHAR2(50), 
	"VERKAUFSPREIS" NUMBER, 
	"JAHRESUMSATZ" NUMBER, 
	"ZEITSTEMPEL" DATE
   ) ;
--------------------------------------------------------
--  DDL for Table AUFTRAEGE
--------------------------------------------------------

  CREATE TABLE "AUFTRAEGE" 
   (	"AUFTRAGSNR" NUMBER(38,0), 
	"AUFTRAGS_TYP" VARCHAR2(50), 
	"KUN_NR" NUMBER(38,0), 
	"ANG_NR" NUMBER(38,0), 
	"BEREITS_GEZAHLT" NUMBER, 
	"BESTELLDATUM" DATE, 
	"LIEFERDATUM" DATE, 
	"RECHNUNGSDATUM" DATE, 
	"ZEITSTEMPEL" DATE
   ) ;
--------------------------------------------------------
--  DDL for Table AUFTRAGSPOSITIONEN
--------------------------------------------------------

  CREATE TABLE "AUFTRAGSPOSITIONEN" 
   (	"TNR" NUMBER(38,0), 
	"AUFTRAGSNR" NUMBER(38,0), 
	"MENGE" NUMBER
   ) ;
--------------------------------------------------------
--  DDL for Table GEH_KLASSEN
--------------------------------------------------------

  CREATE TABLE "GEH_KLASSEN" 
   (	"GEH_KLASSE" NUMBER(38,0), 
	"MAX_GEHALT" NUMBER, 
	"MIN_GEHALT" NUMBER
   ) ;
--------------------------------------------------------
--  DDL for Table KUNDEN
--------------------------------------------------------

  CREATE TABLE "KUNDEN" 
   (	"KUN_NR" NUMBER(38,0), 
	"NACHNAME" VARCHAR2(50), 
	"VORNAME" VARCHAR2(50), 
	"GESCHLECHT" VARCHAR2(1), 
	"ORT" VARCHAR2(50), 
	"STRASSE" VARCHAR2(50), 
	"TELEFONNR" VARCHAR2(50), 
	"ZEITSTEMPEL" DATE
   ) ;
--------------------------------------------------------
--  DDL for Table LAGER
--------------------------------------------------------

  CREATE TABLE "LAGER" 
   (	"LANR" NUMBER(38,0), 
	"BEZEICHNUNG" VARCHAR2(50), 
	"ORT" VARCHAR2(50), 
	"STRASSE" VARCHAR2(50)
   ) ;
--------------------------------------------------------
--  DDL for Table LAGERBESTAND
--------------------------------------------------------

  CREATE TABLE "LAGERBESTAND" 
   (	"LANR" NUMBER(38,0), 
	"TNR" NUMBER(38,0), 
	"BESTAND" NUMBER, 
	"ZEITSTEMPEL" DATE
   ) ;
--------------------------------------------------------
--  DDL for Table LIEFERANTEN
--------------------------------------------------------

  CREATE TABLE "LIEFERANTEN" 
   (	"LIEF_NR" NUMBER(38,0), 
	"NAME" VARCHAR2(50), 
	"ORT" VARCHAR2(50), 
	"STRASSE" VARCHAR2(50), 
	"TELEFONNR" VARCHAR2(50), 
	"ZEITSTEMPEL" DATE
   ) ;
--------------------------------------------------------
--  DDL for Table LIEFERPROGRAMME
--------------------------------------------------------

  CREATE TABLE "LIEFERPROGRAMME" 
   (	"LIEF_NR" NUMBER(38,0), 
	"TNR" NUMBER(38,0), 
	"BESTELLNR" VARCHAR2(20), 
	"EINKAUFSPREIS" NUMBER, 
	"GESAMTMENGE" NUMBER, 
	"ZEITSTEMPEL" DATE
   ) ;
--------------------------------------------------------
--  DDL for Table LIEFERUNGEN
--------------------------------------------------------

  CREATE TABLE "LIEFERUNGEN" 
   (	"LIEFER_NR" NUMBER(38,0), 
	"LIEF_NR" NUMBER(38,0), 
	"TNR" NUMBER(38,0), 
	"LIEF_DATUM" DATE, 
	"MENGE" NUMBER DEFAULT 1, 
	"ZEITSTEMPEL" DATE
   ) ;
--------------------------------------------------------
--  DDL for Table ORTE
--------------------------------------------------------

  CREATE TABLE "ORTE" 
   (	"ORT" VARCHAR2(50), 
	"STRASSE" VARCHAR2(50), 
	"PLZ" NUMBER(38,0)
   ) ;
--------------------------------------------------------
--  DDL for Table STRUKTUR
--------------------------------------------------------

  CREATE TABLE "STRUKTUR" 
   (	"OTEIL" NUMBER(38,0), 
	"UTEIL" NUMBER(38,0), 
	"POSITION" NUMBER(38,0), 
	"MENGE" NUMBER, 
	"AUSSCHUSS" NUMBER, 
	"ARBEITSGANG" NUMBER(38,0), 
	"ZEITSTEMPEL" DATE
   ) ;
--------------------------------------------------------
--  DDL for Table TEILE
--------------------------------------------------------

  CREATE TABLE "TEILE" 
   (	"TNR" NUMBER(38,0), 
	"ME" VARCHAR2(10), 
	"BEZEICHNUNG" VARCHAR2(50), 
	"TYP" VARCHAR2(50), 
	"HERSTELLKOSTEN" NUMBER, 
	"EINKAUFSPREIS" NUMBER, 
	"MINDESTBESTAND" NUMBER, 
	"BESTAND" NUMBER, 
	"LIEFERZEIT" NUMBER, 
	"HERSTELLDAUER" NUMBER, 
	"GEWICHT" NUMBER, 
	"RESERVIERT" NUMBER, 
	"VERFUEGBAR" NUMBER, 
	"ZEITSTEMPEL" DATE
   ) ;
--------------------------------------------------------
--  DDL for Table TEILE_WERKE
--------------------------------------------------------

  CREATE TABLE "TEILE_WERKE" 
   (	"TNR" NUMBER(38,0), 
	"WNR" NUMBER(38,0)
   ) ;
--------------------------------------------------------
--  DDL for Table WERKE
--------------------------------------------------------

  CREATE TABLE "WERKE" 
   (	"WNR" NUMBER(38,0), 
	"BEZEICHNUNG" VARCHAR2(50), 
	"ORT" VARCHAR2(50), 
	"STRASSE" VARCHAR2(50)
   ) ;
--------------------------------------------------------
--  DDL for Index ABT_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ABT_PK" ON "ABTEILUNGEN" ("ABT_NR") 
  ;
--------------------------------------------------------
--  DDL for Index ANG_ABT_FK_I
--------------------------------------------------------

  CREATE INDEX "ANG_ABT_FK_I" ON "ANGESTELLTE" ("ABT_NR") 
  ;
--------------------------------------------------------
--  DDL for Index ANG_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "ANG_PK" ON "ANGESTELLTE" ("ANG_NR") 
  ;
--------------------------------------------------------
--  DDL for Index AR_AU_AR_FK_I
--------------------------------------------------------

  CREATE INDEX "AR_AU_AR_FK_I" ON "AUFTRAGSPOSITIONEN" ("TNR") 
  ;
--------------------------------------------------------
--  DDL for Index AR_AU_AU_FK_I
--------------------------------------------------------

  CREATE INDEX "AR_AU_AU_FK_I" ON "AUFTRAGSPOSITIONEN" ("AUFTRAGSNR") 
  ;
--------------------------------------------------------
--  DDL for Index AR_AU_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "AR_AU_PK" ON "AUFTRAGSPOSITIONEN" ("TNR", "AUFTRAGSNR") 
  ;
--------------------------------------------------------
--  DDL for Index AR_T_FK_I
--------------------------------------------------------

  CREATE INDEX "AR_T_FK_I" ON "ARTIKEL" ("TNR") 
  ;
--------------------------------------------------------
--  DDL for Index AU_ANG_FK_I
--------------------------------------------------------

  CREATE INDEX "AU_ANG_FK_I" ON "AUFTRAEGE" ("ANG_NR") 
  ;
--------------------------------------------------------
--  DDL for Index AU_KUN_FK_I
--------------------------------------------------------

  CREATE INDEX "AU_KUN_FK_I" ON "AUFTRAEGE" ("KUN_NR") 
  ;
--------------------------------------------------------
--  DDL for Index AU_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "AU_PK" ON "AUFTRAEGE" ("AUFTRAGSNR") 
  ;
--------------------------------------------------------
--  DDL for Index G_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "G_PK" ON "GEH_KLASSEN" ("GEH_KLASSE") 
  ;
--------------------------------------------------------
--  DDL for Index KUNDEN_I
--------------------------------------------------------

  CREATE INDEX "KUNDEN_I" ON "KUNDEN" ("VORNAME", "NACHNAME") 
  ;
--------------------------------------------------------
--  DDL for Index KUN_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "KUN_PK" ON "KUNDEN" ("KUN_NR") 
  ;
--------------------------------------------------------
--  DDL for Index LAG_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "LAG_PK" ON "LAGER" ("LANR") 
  ;
--------------------------------------------------------
--  DDL for Index LAG_T_LAG_FK_I
--------------------------------------------------------

  CREATE INDEX "LAG_T_LAG_FK_I" ON "LAGERBESTAND" ("LANR") 
  ;
--------------------------------------------------------
--  DDL for Index LAG_T_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "LAG_T_PK" ON "LAGERBESTAND" ("LANR", "TNR") 
  ;
--------------------------------------------------------
--  DDL for Index LAG_T_T_FK_I
--------------------------------------------------------

  CREATE INDEX "LAG_T_T_FK_I" ON "LAGERBESTAND" ("TNR") 
  ;
--------------------------------------------------------
--  DDL for Index LG_LIEF_FK_I
--------------------------------------------------------

  CREATE INDEX "LG_LIEF_FK_I" ON "LIEFERUNGEN" ("LIEF_NR") 
  ;
--------------------------------------------------------
--  DDL for Index LG_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "LG_PK" ON "LIEFERUNGEN" ("LIEFER_NR", "LIEF_NR", "TNR") 
  ;
--------------------------------------------------------
--  DDL for Index LG_T_FK_I
--------------------------------------------------------

  CREATE INDEX "LG_T_FK_I" ON "LIEFERUNGEN" ("TNR") 
  ;
--------------------------------------------------------
--  DDL for Index LIEF_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "LIEF_PK" ON "LIEFERANTEN" ("LIEF_NR") 
  ;
--------------------------------------------------------
--  DDL for Index LP_LIEF_FK_I
--------------------------------------------------------

  CREATE INDEX "LP_LIEF_FK_I" ON "LIEFERPROGRAMME" ("LIEF_NR") 
  ;
--------------------------------------------------------
--  DDL for Index LP_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "LP_PK" ON "LIEFERPROGRAMME" ("LIEF_NR", "TNR") 
  ;
--------------------------------------------------------
--  DDL for Index LP_T_FK_I
--------------------------------------------------------

  CREATE INDEX "LP_T_FK_I" ON "LIEFERPROGRAMME" ("TNR") 
  ;
--------------------------------------------------------
--  DDL for Index O_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "O_PK" ON "ORTE" ("ORT", "STRASSE") 
  ;
--------------------------------------------------------
--  DDL for Index S_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "S_PK" ON "STRUKTUR" ("OTEIL", "UTEIL", "POSITION") 
  ;
--------------------------------------------------------
--  DDL for Index STRUKTUR_I
--------------------------------------------------------

  CREATE INDEX "STRUKTUR_I" ON "STRUKTUR" ("OTEIL", "UTEIL") 
  ;
--------------------------------------------------------
--  DDL for Index TE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "TE_PK" ON "TEILE" ("TNR") 
  ;
--------------------------------------------------------
--  DDL for Index T_WE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "T_WE_PK" ON "TEILE_WERKE" ("TNR", "WNR") 
  ;
--------------------------------------------------------
--  DDL for Index T_WE_T_FK_I
--------------------------------------------------------

  CREATE INDEX "T_WE_T_FK_I" ON "TEILE_WERKE" ("TNR") 
  ;
--------------------------------------------------------
--  DDL for Index T_WE_WE_FK_I
--------------------------------------------------------

  CREATE INDEX "T_WE_WE_FK_I" ON "TEILE_WERKE" ("WNR") 
  ;
--------------------------------------------------------
--  DDL for Index WE_PK
--------------------------------------------------------

  CREATE UNIQUE INDEX "WE_PK" ON "WERKE" ("WNR") 
  ;


--------------------------------------------------------
--  ALTER Fahrrad DB
--------------------------------------------------------

--------------------------------------------------------
--  Constraints for Table ABTEILUNGEN
--------------------------------------------------------

  ALTER TABLE "ABTEILUNGEN" ADD CONSTRAINT "ABT_PK" PRIMARY KEY ("ABT_NR") ENABLE;
 
  ALTER TABLE "ABTEILUNGEN" MODIFY ("ABT_NR" NOT NULL ENABLE);
 
  ALTER TABLE "ABTEILUNGEN" MODIFY ("LEITER" NOT NULL ENABLE);
 
  ALTER TABLE "ABTEILUNGEN" MODIFY ("NAME" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table ANGESTELLTE
--------------------------------------------------------

  ALTER TABLE "ANGESTELLTE" ADD CONSTRAINT "ANG_PK" PRIMARY KEY ("ANG_NR") ENABLE;
 
  ALTER TABLE "ANGESTELLTE" ADD CONSTRAINT "GESCHLECHT" CHECK ( Geschlecht IN ('w', 'm')) ENABLE;
 
  ALTER TABLE "ANGESTELLTE" MODIFY ("ANG_NR" NOT NULL ENABLE);
 
  ALTER TABLE "ANGESTELLTE" MODIFY ("ABT_NR" NOT NULL ENABLE);
 
  ALTER TABLE "ANGESTELLTE" MODIFY ("AUFGABENBESCHREIBUNG" NOT NULL ENABLE);
 
  ALTER TABLE "ANGESTELLTE" MODIFY ("BERUF" NOT NULL ENABLE);
 
  ALTER TABLE "ANGESTELLTE" MODIFY ("NACHNAME" NOT NULL ENABLE);
 
  ALTER TABLE "ANGESTELLTE" MODIFY ("VORNAME" NOT NULL ENABLE);
 
  ALTER TABLE "ANGESTELLTE" MODIFY ("GESCHLECHT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table ARTIKEL
--------------------------------------------------------

  ALTER TABLE "ARTIKEL" ADD CONSTRAINT "AR_PK" PRIMARY KEY ("TNR") ENABLE;
 
  ALTER TABLE "ARTIKEL" MODIFY ("TNR" NOT NULL ENABLE);
 
  ALTER TABLE "ARTIKEL" MODIFY ("BEZEICHNUNG" NOT NULL ENABLE);
 
  ALTER TABLE "ARTIKEL" MODIFY ("ARTIKEL_TYP" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table AUFTRAEGE
--------------------------------------------------------

  ALTER TABLE "AUFTRAEGE" ADD CONSTRAINT "AUFTRAGS_TYP" CHECK (Auftrags_Typ IN ('Angebot', 'Anfrage', 'Auftrag')) ENABLE;
 
  ALTER TABLE "AUFTRAEGE" ADD CONSTRAINT "AU_PK" PRIMARY KEY ("AUFTRAGSNR") ENABLE;
 
  ALTER TABLE "AUFTRAEGE" ADD CONSTRAINT "DATUM" CHECK (Bestelldatum <= Lieferdatum) ENABLE;
 
  ALTER TABLE "AUFTRAEGE" MODIFY ("AUFTRAGSNR" NOT NULL ENABLE);
 
  ALTER TABLE "AUFTRAEGE" MODIFY ("AUFTRAGS_TYP" NOT NULL ENABLE);
 
  ALTER TABLE "AUFTRAEGE" MODIFY ("KUN_NR" NOT NULL ENABLE);
 
  ALTER TABLE "AUFTRAEGE" MODIFY ("ZEITSTEMPEL" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table AUFTRAGSPOSITIONEN
--------------------------------------------------------

  ALTER TABLE "AUFTRAGSPOSITIONEN" ADD CONSTRAINT "AR_AU_PK" PRIMARY KEY ("TNR", "AUFTRAGSNR") ENABLE;
 
  ALTER TABLE "AUFTRAGSPOSITIONEN" MODIFY ("TNR" NOT NULL ENABLE);
 
  ALTER TABLE "AUFTRAGSPOSITIONEN" MODIFY ("AUFTRAGSNR" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table GEH_KLASSEN
--------------------------------------------------------

  ALTER TABLE "GEH_KLASSEN" ADD CONSTRAINT "G_PK" PRIMARY KEY ("GEH_KLASSE") ENABLE;
 
  ALTER TABLE "GEH_KLASSEN" MODIFY ("GEH_KLASSE" NOT NULL ENABLE);
 
  ALTER TABLE "GEH_KLASSEN" MODIFY ("MAX_GEHALT" NOT NULL ENABLE);
 
  ALTER TABLE "GEH_KLASSEN" MODIFY ("MIN_GEHALT" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table KUNDEN
--------------------------------------------------------

  ALTER TABLE "KUNDEN" ADD CONSTRAINT "KUN_PK" PRIMARY KEY ("KUN_NR") ENABLE;
 
  ALTER TABLE "KUNDEN" MODIFY ("KUN_NR" NOT NULL ENABLE);
 
  ALTER TABLE "KUNDEN" MODIFY ("NACHNAME" NOT NULL ENABLE);
 
  ALTER TABLE "KUNDEN" MODIFY ("VORNAME" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table LAGER
--------------------------------------------------------

  ALTER TABLE "LAGER" ADD CONSTRAINT "LAG_PK" PRIMARY KEY ("LANR") ENABLE;
 
  ALTER TABLE "LAGER" MODIFY ("LANR" NOT NULL ENABLE);
 
  ALTER TABLE "LAGER" MODIFY ("BEZEICHNUNG" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table LAGERBESTAND
--------------------------------------------------------

  ALTER TABLE "LAGERBESTAND" ADD CONSTRAINT "LAG_T_PK" PRIMARY KEY ("LANR", "TNR") ENABLE;
 
  ALTER TABLE "LAGERBESTAND" MODIFY ("LANR" NOT NULL ENABLE);
 
  ALTER TABLE "LAGERBESTAND" MODIFY ("TNR" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table LIEFERANTEN
--------------------------------------------------------

  ALTER TABLE "LIEFERANTEN" ADD CONSTRAINT "LIEF_PK" PRIMARY KEY ("LIEF_NR") ENABLE;
 
  ALTER TABLE "LIEFERANTEN" MODIFY ("LIEF_NR" NOT NULL ENABLE);
 
  ALTER TABLE "LIEFERANTEN" MODIFY ("NAME" NOT NULL ENABLE);
 
  ALTER TABLE "LIEFERANTEN" MODIFY ("ORT" NOT NULL ENABLE);
 
  ALTER TABLE "LIEFERANTEN" MODIFY ("STRASSE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table LIEFERPROGRAMME
--------------------------------------------------------

  ALTER TABLE "LIEFERPROGRAMME" ADD CONSTRAINT "LP_PK" PRIMARY KEY ("LIEF_NR", "TNR") ENABLE;
 
  ALTER TABLE "LIEFERPROGRAMME" MODIFY ("LIEF_NR" NOT NULL ENABLE);
 
  ALTER TABLE "LIEFERPROGRAMME" MODIFY ("TNR" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table LIEFERUNGEN
--------------------------------------------------------

  ALTER TABLE "LIEFERUNGEN" ADD CONSTRAINT "LG_PK" PRIMARY KEY ("LIEFER_NR", "LIEF_NR", "TNR") ENABLE;
 
  ALTER TABLE "LIEFERUNGEN" MODIFY ("LIEFER_NR" NOT NULL ENABLE);
 
  ALTER TABLE "LIEFERUNGEN" MODIFY ("LIEF_NR" NOT NULL ENABLE);
 
  ALTER TABLE "LIEFERUNGEN" MODIFY ("TNR" NOT NULL ENABLE);
 
  ALTER TABLE "LIEFERUNGEN" MODIFY ("LIEF_DATUM" NOT NULL ENABLE);
 
  ALTER TABLE "LIEFERUNGEN" MODIFY ("MENGE" NOT NULL ENABLE);
 
  ALTER TABLE "LIEFERUNGEN" MODIFY ("ZEITSTEMPEL" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table ORTE
--------------------------------------------------------

  ALTER TABLE "ORTE" ADD CONSTRAINT "O_PK" PRIMARY KEY ("ORT", "STRASSE") ENABLE;
 
  ALTER TABLE "ORTE" MODIFY ("ORT" NOT NULL ENABLE);
 
  ALTER TABLE "ORTE" MODIFY ("STRASSE" NOT NULL ENABLE);
--------------------------------------------------------
--  Constraints for Table STRUKTUR
--------------------------------------------------------

  ALTER TABLE "STRUKTUR" MODIFY ("OTEIL" NOT NULL ENABLE);
 
  ALTER TABLE "STRUKTUR" MODIFY ("UTEIL" NOT NULL ENABLE);
 
  ALTER TABLE "STRUKTUR" MODIFY ("POSITION" NOT NULL ENABLE);
 
  ALTER TABLE "STRUKTUR" MODIFY ("MENGE" NOT NULL ENABLE);
 
  ALTER TABLE "STRUKTUR" ADD CONSTRAINT "S_PK" PRIMARY KEY ("OTEIL", "UTEIL", "POSITION") ENABLE;
--------------------------------------------------------
--  Constraints for Table TEILE
--------------------------------------------------------

  ALTER TABLE "TEILE" MODIFY ("TNR" NOT NULL ENABLE);
 
  ALTER TABLE "TEILE" ADD CONSTRAINT "TE_PK" PRIMARY KEY ("TNR") ENABLE;
 
  ALTER TABLE "TEILE" ADD CONSTRAINT "TYP" CHECK ( Typ IN ('Artikel', 'Baugruppe', 'Material')) ENABLE;
--------------------------------------------------------
--  Constraints for Table TEILE_WERKE
--------------------------------------------------------

  ALTER TABLE "TEILE_WERKE" MODIFY ("TNR" NOT NULL ENABLE);
 
  ALTER TABLE "TEILE_WERKE" MODIFY ("WNR" NOT NULL ENABLE);
 
  ALTER TABLE "TEILE_WERKE" ADD CONSTRAINT "T_WE_PK" PRIMARY KEY ("TNR", "WNR") ENABLE;
--------------------------------------------------------
--  Constraints for Table WERKE
--------------------------------------------------------

  ALTER TABLE "WERKE" MODIFY ("WNR" NOT NULL ENABLE);
 
  ALTER TABLE "WERKE" MODIFY ("ORT" NOT NULL ENABLE);
 
  ALTER TABLE "WERKE" MODIFY ("STRASSE" NOT NULL ENABLE);
 
  ALTER TABLE "WERKE" ADD CONSTRAINT "WE_PK" PRIMARY KEY ("WNR") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table ANGESTELLTE
--------------------------------------------------------

  ALTER TABLE "ANGESTELLTE" ADD CONSTRAINT "ANG_ABT_FK" FOREIGN KEY ("ABT_NR")
	  REFERENCES "ABTEILUNGEN" ("ABT_NR") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table ARTIKEL
--------------------------------------------------------

  ALTER TABLE "ARTIKEL" ADD CONSTRAINT "AR_T_FK" FOREIGN KEY ("TNR")
	  REFERENCES "TEILE" ("TNR") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table AUFTRAEGE
--------------------------------------------------------

  ALTER TABLE "AUFTRAEGE" ADD CONSTRAINT "AU_ANG_FK" FOREIGN KEY ("ANG_NR")
	  REFERENCES "ANGESTELLTE" ("ANG_NR") ENABLE;
 
  ALTER TABLE "AUFTRAEGE" ADD CONSTRAINT "AU_KUN_FK" FOREIGN KEY ("KUN_NR")
	  REFERENCES "KUNDEN" ("KUN_NR") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table AUFTRAGSPOSITIONEN
--------------------------------------------------------

  ALTER TABLE "AUFTRAGSPOSITIONEN" ADD CONSTRAINT "AR_AU_AR_FK" FOREIGN KEY ("TNR")
	  REFERENCES "ARTIKEL" ("TNR") ENABLE;
 
  ALTER TABLE "AUFTRAGSPOSITIONEN" ADD CONSTRAINT "AR_AU_AU_FK" FOREIGN KEY ("AUFTRAGSNR")
	  REFERENCES "AUFTRAEGE" ("AUFTRAGSNR") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table LAGERBESTAND
--------------------------------------------------------

  ALTER TABLE "LAGERBESTAND" ADD CONSTRAINT "LAG_T_LAG_FK" FOREIGN KEY ("LANR")
	  REFERENCES "LAGER" ("LANR") ENABLE;
 
  ALTER TABLE "LAGERBESTAND" ADD CONSTRAINT "LAG_T_T_FK" FOREIGN KEY ("TNR")
	  REFERENCES "TEILE" ("TNR") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table LIEFERPROGRAMME
--------------------------------------------------------

  ALTER TABLE "LIEFERPROGRAMME" ADD CONSTRAINT "LP_LIEF_FK" FOREIGN KEY ("LIEF_NR")
	  REFERENCES "LIEFERANTEN" ("LIEF_NR") ENABLE;
 
  ALTER TABLE "LIEFERPROGRAMME" ADD CONSTRAINT "LP_T_FK" FOREIGN KEY ("TNR")
	  REFERENCES "TEILE" ("TNR") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table LIEFERUNGEN
--------------------------------------------------------

  ALTER TABLE "LIEFERUNGEN" ADD CONSTRAINT "LG_LIEF_FK" FOREIGN KEY ("LIEF_NR")
	  REFERENCES "LIEFERANTEN" ("LIEF_NR") ENABLE;
 
  ALTER TABLE "LIEFERUNGEN" ADD CONSTRAINT "LG_T_FK" FOREIGN KEY ("TNR")
	  REFERENCES "TEILE" ("TNR") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table STRUKTUR
--------------------------------------------------------

  ALTER TABLE "STRUKTUR" ADD CONSTRAINT "S_T_FK" FOREIGN KEY ("OTEIL")
	  REFERENCES "TEILE" ("TNR") ENABLE;
 
  ALTER TABLE "STRUKTUR" ADD CONSTRAINT "S_T_FK2" FOREIGN KEY ("UTEIL")
	  REFERENCES "TEILE" ("TNR") ENABLE;
--------------------------------------------------------
--  Ref Constraints for Table TEILE_WERKE
--------------------------------------------------------

  ALTER TABLE "TEILE_WERKE" ADD CONSTRAINT "T_WE_T_FK" FOREIGN KEY ("TNR")
	  REFERENCES "TEILE" ("TNR") ENABLE;
 
  ALTER TABLE "TEILE_WERKE" ADD CONSTRAINT "T_WE_WE_FK" FOREIGN KEY ("WNR")
	  REFERENCES "WERKE" ("WNR") ENABLE;
