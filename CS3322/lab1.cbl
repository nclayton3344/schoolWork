      ******************************************************************
      * Author:Nathaniel Clayton
      * Date:09/10/2018
      * Purpose: Lab1 Assignment
      ******************************************************************
       IDENTIFICATION DIVISION.
       PROGRAM-ID. LAB1.
       AUTHOR. N. D. CLAYTON.
       INSTALLATION. WTAMU CS3322.
       DATE-WRITTEN. 09/10/2018.
       DATE-COMPILED. 09/12/2018.
       SECURITY. CONFIDENTIAL.
       DATA DIVISION.
       WORKING-STORAGE SECTION.
       01 MORE-DATA PIC X(3) VALUE "YES".
       01 CUSTOMER-NAME PIC X(20).
       01 PURCHASE-AMOUNT PIC 99999V99.
       01 AMOUNT-OWED PIC 99999.99.
       PROCEDURE DIVISION.
       100-MAIN.
           PERFORM UNTIL MORE-DATA = 'NO'
               DISPLAY 'ENTER THE CUSTOMER NAME'
               ACCEPT CUSTOMER-NAME
               DISPLAY 'WHAT IS THE PURCHASE AMOUNT?'
               ACCEPT PURCHASE-AMOUNT
               COMPUTE AMOUNT-OWED = PURCHASE-AMOUNT -
               0.1 * PURCHASE-AMOUNT
               DISPLAY CUSTOMER-NAME 'OWES ' AMOUNT-OWED
               DISPLAY 'IS THERE MORE INPUT (YES OR NO)?'
               ACCEPT MORE-DATA
            END-PERFORM
            STOP RUN.
       END PROGRAM LAB1.
