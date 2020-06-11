/*
 * flow.c
 *
 *  Created on: 27-May-2020
 *      Author: sumit.ranjan
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ns_string.h"

void flow()
{
 ns_web_add_auto_header("x-forwarded-server","macys.com", 0);
 ns_advance_param("cslcookie");
 ns_advance_param("StoreSDDR");
 ns_add_cookie_val_ex("CSL", ".macys.com", "/", ns_eval_string("{cslcookie}"));
 ns_add_cookie_val_ex("SFL", ".macys.com", "/", ns_eval_string("{StoreSDDR}"));

	ns_start_transaction("HomePageCanvas_H03");
    ns_web_url ("HomePageCanvas_H03",
    	"URL=https://www.macys.com/xapi/homepage/v1/canvas",
		"HEADER={DynaTraceHdr}",
		"HEADER=ThrottleToBagApp:true",
		"HEADER=Accept-Language:en-US,en;q=0.8",
        "PreSnapshot=webpage_1462520471298.png",
        "Snapshot=webpage_1462520533969.png"
            );
     ns_end_transaction("HomePageCanvas_H03", NS_AUTO_STATUS);
    ns_page_think_time(0);

             int k=1;
    ns_advance_param("Count1");
    ns_advance_param("productid");
   int count2 = ns_get_int_val("Count1");
        printf ("**** Count of product is %d *** \n",count2);
        int flag=0;
    char temp[86810];
    temp[0]='\0';
        for (k=1;k<=count2;k++)
        {

        if(flag==0)
             {
                        ns_advance_param("productid");
                        strcat(temp,ns_eval_string("{productid}"));
                        flag=1;
               }
                else
                {
                        ns_advance_param("productid");
                        strcat(temp, ",");
                    strcat(temp,ns_eval_string("{productid}"));
                }
        }
                        ns_save_string(temp,"All_ProdId");
                  printf (" the Product is %s \n",ns_eval_string("{All_ProdId}"));

    ns_start_transaction("HomeV1Product_H03");
    ns_web_url ("HomeV1Product_H03",
    	"URL=https://www.macys.com/xapi/discover/v1/product?productIds={All_ProdId}&clientId=PROS&_shoppingMode=SITE&_customerState=RECOGNIZED&currencyCode=USD&_regionCode=US",
		"HEADER={DynaTraceHdr}",
		"HEADER=ThrottleToBagApp:true",
		 "HEADER=Accept-Language:en-US,en;q=0.8",
        "PreSnapshot=webpage_1462520471298.png",
        "Snapshot=webpage_1462520533969.png"
        );
     ns_end_transaction("HomeV1Product_H03", NS_AUTO_STATUS);
    ns_page_think_time(0);

}
