--------------------------------------------------------
--  DATABASE SALES INSERT DATA
--------------------------------------------------------

--------------------------------------------------------
--  INSERT DATA INTO TABLES
--------------------------------------------------------


-- INSERTING into POSTCODES
Insert into POSTCODES (POSTCODE,CITY) values (1010,'Vienna');
Insert into POSTCODES (POSTCODE,CITY) values (1200,'Vienna');
Insert into POSTCODES (POSTCODE,CITY) values (4200,'Linz');


-- INSERTING into ADDRESSES
Insert into ADDRESSES (ADDRESSES_ID,STREET,POSTCODE) values (1,'Werdertorgasse 12',1010);
Insert into ADDRESSES (ADDRESSES_ID,STREET,POSTCODE) values (2,'Getreidemarkt 5',1010);
Insert into ADDRESSES (ADDRESSES_ID,STREET,POSTCODE) values (3,'Allerheiligenplatz 15',1200);
Insert into ADDRESSES (ADDRESSES_ID,STREET,POSTCODE) values (4,'Höchstädtplatz 5',1200);
Insert into ADDRESSES (ADDRESSES_ID,STREET,POSTCODE) values (5,'Hauptstrasse 17',4200);


-- INSERTING into CUSTOMERS
Insert into CUSTOMERS (CUSTOMERS_ID,CUSTOMERS_NAME,CUSTOMERS_PRENAME,ADDRESSES_ID) values (1,'Kingfisher','Karl',1);
Insert into CUSTOMERS (CUSTOMERS_ID,CUSTOMERS_NAME,CUSTOMERS_PRENAME,ADDRESSES_ID) values (2,'Muster','Rudolf',2);
Insert into CUSTOMERS (CUSTOMERS_ID,CUSTOMERS_NAME,CUSTOMERS_PRENAME,ADDRESSES_ID) values (3,'Maier','Peter',3);
Insert into CUSTOMERS (CUSTOMERS_ID,CUSTOMERS_NAME,CUSTOMERS_PRENAME,ADDRESSES_ID) values (4,'Bauer','Anna',4);
Insert into CUSTOMERS (CUSTOMERS_ID,CUSTOMERS_NAME,CUSTOMERS_PRENAME,ADDRESSES_ID) values (5,'Fischer','Sigrid',5);


-- INSERTING into ORDERS
Insert into ORDERS (ORDERS_ID,ORDERS_DATE,REQUIRED_DATE,SHIPPED_DATE,STATUS,CUSTOMERS_ID) values (3,to_date('14-NOV-17','DD-MON-RR'),to_date('16-NOV-17','DD-MON-RR'),to_date('16-MAR-18','DD-MON-RR'),'ok',3);
Insert into ORDERS (ORDERS_ID,ORDERS_DATE,REQUIRED_DATE,SHIPPED_DATE,STATUS,CUSTOMERS_ID) values (4,to_date('10-FEB-18','DD-MON-RR'),to_date('12-FEB-18','DD-MON-RR'),to_date('11-APR-18','DD-MON-RR'),'ok',4);
Insert into ORDERS (ORDERS_ID,ORDERS_DATE,REQUIRED_DATE,SHIPPED_DATE,STATUS,CUSTOMERS_ID) values (5,to_date('10-APR-19','DD-MON-RR'),to_date('10-MAY-19','DD-MON-RR'),to_date('11-JUN-19','DD-MON-RR'),'ok',5);
Insert into ORDERS (ORDERS_ID,ORDERS_DATE,REQUIRED_DATE,SHIPPED_DATE,STATUS,CUSTOMERS_ID) values (6,to_date('01-JUN-19','DD-MON-RR'),to_date('01-JUN-19','DD-MON-RR'),to_date('03-AUG-19','DD-MON-RR'),'ok',5);
Insert into ORDERS (ORDERS_ID,ORDERS_DATE,REQUIRED_DATE,SHIPPED_DATE,STATUS,CUSTOMERS_ID) values (7,to_date('05-AUG-19','DD-MON-RR'),to_date('06-SEP-19','DD-MON-RR'),to_date('07-SEP-19','DD-MON-RR'),'ok',3);
Insert into ORDERS (ORDERS_ID,ORDERS_DATE,REQUIRED_DATE,SHIPPED_DATE,STATUS,CUSTOMERS_ID) values (8,to_date('05-SEP-19','DD-MON-RR'),to_date('07-SEP-19','DD-MON-RR'),to_date('08-SEP-19','DD-MON-RR'),'ok',3);
Insert into ORDERS (ORDERS_ID,ORDERS_DATE,REQUIRED_DATE,SHIPPED_DATE,STATUS,CUSTOMERS_ID) values (9,to_date('01-JAN-20','DD-MON-RR'),to_date('02-FEB-20','DD-MON-RR'),to_date('03-FEB-20','DD-MON-RR'),'delayed',1);
Insert into ORDERS (ORDERS_ID,ORDERS_DATE,REQUIRED_DATE,SHIPPED_DATE,STATUS,CUSTOMERS_ID) values (10,to_date('03-MAR-20','DD-MON-RR'),to_date('04-APR-20','DD-MON-RR'),to_date('03-MAY-20','DD-MON-RR'),'delayed',1);
Insert into ORDERS (ORDERS_ID,ORDERS_DATE,REQUIRED_DATE,SHIPPED_DATE,STATUS,CUSTOMERS_ID) values (11,to_date('14-JAN-20','DD-MON-RR'),to_date('02-FEB-20','DD-MON-RR'),to_date('05-MAY-20','DD-MON-RR'),'delayed',3);
Insert into ORDERS (ORDERS_ID,ORDERS_DATE,REQUIRED_DATE,SHIPPED_DATE,STATUS,CUSTOMERS_ID) values (1,to_date('09-AUG-20','DD-MON-RR'),to_date('09-AUG-20','DD-MON-RR'),to_date('09-AUG-20','DD-MON-RR'),'ok',1);
Insert into ORDERS (ORDERS_ID,ORDERS_DATE,REQUIRED_DATE,SHIPPED_DATE,STATUS,CUSTOMERS_ID) values (2,to_date('09-AUG-20','DD-MON-RR'),to_date('09-AUG-20','DD-MON-RR'),to_date('09-AUG-20','DD-MON-RR'),'ok',2);


-- INSERTING into PRODUCTS
Insert into PRODUCTS (PRODUCTS_ID,PRODUCTS_NAME,PRODUCTS_DESCRIPTION) values (1,'car','cars and radio controlled');
Insert into PRODUCTS (PRODUCTS_ID,PRODUCTS_NAME,PRODUCTS_DESCRIPTION) values (2,'lego','cars and radio controlled');
Insert into PRODUCTS (PRODUCTS_ID,PRODUCTS_NAME,PRODUCTS_DESCRIPTION) values (3,'megablocks','cars and radio controlled');
Insert into PRODUCTS (PRODUCTS_ID,PRODUCTS_NAME,PRODUCTS_DESCRIPTION) values (4,'magnetic Poetry','creative toys');


-- INSERTING into ORDERS_PRODUCTS
Insert into ORDERS_PRODUCTS (ORDERS_ID,PRODUCTS_ID,QUANTITY,COST) values (1,1,10,11);
Insert into ORDERS_PRODUCTS (ORDERS_ID,PRODUCTS_ID,QUANTITY,COST) values (2,2,20,21);
Insert into ORDERS_PRODUCTS (ORDERS_ID,PRODUCTS_ID,QUANTITY,COST) values (3,3,15,16);

COMMIT;

