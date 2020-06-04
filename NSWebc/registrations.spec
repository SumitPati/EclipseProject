//made format changes
nsl_web_find(TEXT="xx-xx-xx-xx.index", PAGE=HomePageCanvas_H03);
nsl_web_find(TEXT="\"product\":{\"id\"", PAGE=HomeV1Product_H03);
nsl_static_var(productid:3, File=/home/cavisson/work/mixedloadData/Prodid_upcid_Catid_ProdInfo.txt, Refresh=USE, Mode=RANDOM, EncodeMode=All, CopyFileToTR=Yes);
nsl_decl_var(All_ProdId);
nsl_static_var(Count1:1, File=/home/cavisson/work/mixedloadData/ProdCount, Refresh=USE, Mode=RANDOM, EncodeMode=All, CopyFileToTR=Yes);
nsl_static_var(Count2:1, File=/home/cavisson/work/mixedloadData/LocCount, Refresh=USE, Mode=RANDOM, EncodeMode=All, CopyFileToTR=Yes);
nsl_static_var(StoreSDDR:1, File=/home/cavisson/work/mixedloadData/PRODLOGS/StoreNumber_SDDR, Refresh=SESSION, Mode=RANDOM, EncodeMode=All, CopyFileToTR=Yes);
nsl_static_var(cslcookie:1, File=/home/cavisson/work/mixedloadData/PRODLOGS/cslcookie.txt, Refresh=SESSION, Mode=RANDOM, FirstDataLine=1, EncodeMode=All, EncodeSpaceBy=%20);