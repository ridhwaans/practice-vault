#!/usr/bin/env python
import os
import numpy
import pandas 
import argparse
from datetime import datetime
import __builtin__

def main():
    parser = argparse.ArgumentParser(description="Five product types with the best peak / non-peak sales ratio")
    parser.add_argument("sales_data", type=lambda x: validate(parser, x), help="SalesData.csv file")
    parser.add_argument("product_data", type=lambda y: validate(parser, y), help="ProductData.json file")
    args = parser.parse_args()
    sales_data = pandas.read_csv(args.sales_data)
    sales_data.Ship_Date = pandas.to_datetime(sales_data.Ship_Date, format='%Y-%m-%d %H:%M:%S.%f')

    peak_products = sales_data[sales_data.Ship_Date.dt.month.isin([10,11,12])]
    peak_products = peak_products.Product_ID.value_counts() #.nlargest(5)
    print(peak_products)

    non_peak_products = sales_data[sales_data.Ship_Date.dt.month.between(1,9, inclusive=True)]
    non_peak_products = non_peak_products.Product_ID.value_counts()   #.nsmallest(5)
    #print(non_peak_products)
    
    common_products = pandas.merge(peak_products, non_peak_products, on='Product_ID', how='inner')
    print(common_products)
    #df = df.loc[(df['Ship_Date']>=date1) & (df['Ship_Date']<=date2)]
    #print(df.iloc[:10,:10])    

def validate(parser, arg):
    arg = os.path.abspath(arg)
    if not os.path.exists(arg):
        parser.error("The file '%s' does not exist. Try again" % arg)
    else:
        return arg

if __name__ == "__main__":
    main()

'''
sales_data.Ship_Date >

df.loc[datetime.date(month=10,day=1):datetime.date(month=12,day=31)]

airports[(airports.iso_region == 'US-CA') & (airports.type == 'seaplane_base')]

airports[(airports.iso_region == 'US-CA') & (airports.type == 'large_airport')]
[['Product_ID', 'COUNT(Product_ID)']]

airports.groupby(['Product_ID'])

.sort_values('COUNT(Product_ID)')
'''