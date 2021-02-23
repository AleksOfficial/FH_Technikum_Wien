--------------------------------------------------------
--  CREATE DATABASE SALES
--------------------------------------------------------

--------------------------------------------------------
--  CREATE TABLES
--------------------------------------------------------

--------------------------------------------------------
--  DDL for Table ADDRESSES
--------------------------------------------------------

  CREATE TABLE "ADDRESSES" (
	"ADDRESSES_ID" NUMBER(10,0) PRIMARY KEY, 
	"STREET" VARCHAR2(50 BYTE), 
	"POSTCODE" NUMBER(7,0)
   ) ;


--------------------------------------------------------
--  DDL for Table CUSTOMERS
--------------------------------------------------------

  CREATE TABLE "CUSTOMERS" (
	"CUSTOMERS_ID" NUMBER(10,0) PRIMARY KEY, 
	"CUSTOMERS_NAME" VARCHAR2(50 BYTE), 
	"CUSTOMERS_PRENAME" VARCHAR2(50 BYTE), 
	"ADDRESSES_ID" NUMBER(10,0)
   ) ;


--------------------------------------------------------
--  DDL for Table ORDERS
--------------------------------------------------------

  CREATE TABLE "ORDERS" (
	"ORDERS_ID" NUMBER(10,0) PRIMARY KEY, 
	"ORDERS_DATE" DATE, 
	"REQUIRED_DATE" DATE, 
	"SHIPPED_DATE" DATE, 
	"STATUS" VARCHAR2(50 BYTE), 
	"CUSTOMERS_ID" NUMBER(10,0)
   ) ;


--------------------------------------------------------
--  DDL for Table ORDERS_PRODUCTS
--------------------------------------------------------

  CREATE TABLE "ORDERS_PRODUCTS" (
	"ORDERS_ID" NUMBER(10,0), 
	"PRODUCTS_ID" NUMBER(10,0), 
	"QUANTITY" NUMBER(10,0), 
	"COST" NUMBER(10,0),
	PRIMARY KEY ("ORDERS_ID", "PRODUCTS_ID")
   ) ;


--------------------------------------------------------
--  DDL for Table PRODUCTS
--------------------------------------------------------

  CREATE TABLE "PRODUCTS" (
	"PRODUCTS_ID" NUMBER(10,0) PRIMARY KEY, 
	"PRODUCTS_NAME" VARCHAR2(50 BYTE), 
	"PRODUCTS_DESCRIPTION" VARCHAR2(50 BYTE)
   ) ;


--------------------------------------------------------
--  DDL for Table POSTCODES
--------------------------------------------------------

  CREATE TABLE "POSTCODES" (
	"POSTCODE" NUMBER(7,0) PRIMARY KEY, 
	"CITY" VARCHAR2(50 BYTE)
   ) ;



--------------------------------------------------------
--  ADD CONSTRAINTS
--------------------------------------------------------

--------------------------------------------------------
--  Constraints for Table ADDRESSES
--------------------------------------------------------

  ALTER TABLE "ADDRESSES" MODIFY ("ADDRESSES_ID" NOT NULL ENABLE);
 
  ALTER TABLE "ADDRESSES" MODIFY ("STREET" NOT NULL ENABLE);
  
  ALTER TABLE "ADDRESSES" ADD CONSTRAINT "FK_ADDR_POST" FOREIGN KEY ("POSTCODE") REFERENCES POSTCODES ("POSTCODE") ENABLE;


--------------------------------------------------------
--  Constraints for Table CUSTOMERS
--------------------------------------------------------

  ALTER TABLE "CUSTOMERS" MODIFY ("CUSTOMERS_ID" NOT NULL ENABLE);

  ALTER TABLE "CUSTOMERS" MODIFY ("CUSTOMERS_NAME" NOT NULL ENABLE);
  
  ALTER TABLE "CUSTOMERS" ADD CONSTRAINT "FK_CUST_ADDR" FOREIGN KEY ("ADDRESSES_ID") REFERENCES ADDRESSES ("ADDRESSES_ID") ENABLE;
 


--------------------------------------------------------
--  Constraints for Table ORDERS
--------------------------------------------------------

  ALTER TABLE "ORDERS" MODIFY ("ORDERS_ID" NOT NULL ENABLE);
  
  ALTER TABLE "ORDERS" ADD CONSTRAINT "FK_ORD_CUST" FOREIGN KEY ("CUSTOMERS_ID") REFERENCES CUSTOMERS ("CUSTOMERS_ID") ENABLE;


--------------------------------------------------------
--  Constraints for Table ORDERS_PRODUCTS
--------------------------------------------------------

  ALTER TABLE "ORDERS_PRODUCTS" MODIFY ("ORDERS_ID" NOT NULL ENABLE);
  
  ALTER TABLE "ORDERS_PRODUCTS" MODIFY ("PRODUCTS_ID" NOT NULL ENABLE);
  
  ALTER TABLE "ORDERS_PRODUCTS" ADD CONSTRAINT "FK_OP_ORDERS_ID" FOREIGN KEY ("ORDERS_ID") REFERENCES ORDERS ("ORDERS_ID") ENABLE;
  
  ALTER TABLE "ORDERS_PRODUCTS" ADD CONSTRAINT "FK_OP_PRODUCTS_ID" FOREIGN KEY ("PRODUCTS_ID") REFERENCES PRODUCTS ("PRODUCTS_ID") ENABLE;


--------------------------------------------------------
--  Constraints for Table PRODUCTS
--------------------------------------------------------

  ALTER TABLE "PRODUCTS" MODIFY ("PRODUCTS_ID" NOT NULL ENABLE);
 
  ALTER TABLE "PRODUCTS" MODIFY ("PRODUCTS_NAME" NOT NULL ENABLE);

