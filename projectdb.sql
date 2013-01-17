DROP DATABASE IF EXISTS projectApp;

CREATE DATABASE projectApp;
USE projectApp;

DROP TABLE IF EXISTS entityMap;
CREATE TABLE entityMap 
(
  entityName varchar(255),
  uid varchar(255),
  x int,
  y int
);


DROP TABLE IF EXISTS link;
CREATE TABLE link
(
  entitytype_1 varchar(255) ,
  UID1 varchar(255) ,
  entitytype_2 varchar(255) ,
  UID2 varchar(255) 
);

