#!/usr/bin/env python
import os
import numpy
import pandas 
import argparse
from datetime import datetime
import __builtin__
import json

def main():
    parser = argparse.ArgumentParser(description="Five product types with the best peak / non-peak sales ratio")
    parser.add_argument("sales_data", type=lambda x: validate(parser, x), help="SalesData.csv file")
    parser.add_argument("product_data", type=lambda y: validate(parser, y), help="ProductData.json file")
    args = parser.parse_args()
    sales_data = pandas.read_csv(args.sales_data)
    sales_data.Ship_Date = pandas.to_datetime(sales_data.Ship_Date, format='%Y-%m-%d %H:%M:%S.%f')
    #sales_data['frequency'] = sales_data.groupby('Product_ID')['Product_ID'].transform('count')
    #sales_data.set_index('Product_ID', inplace=True)
    sales_data.sort_values('Product_ID', inplace=True)

    with open(args.product_data) as file:
        product_data = json.load(file)

    peak_products = sales_data[sales_data.Ship_Date.dt.month.isin([10,11,12])]
    #peak_products = peak_products.Product_ID.value_counts().sort_index() #.nlargest(5)
    #peak_products['frequency'] = peak_products.groupby('Product_ID')['Product_ID'].transform('count')
    #peak_products.reset_index(drop=True, inplace=True)
    #peak_products.set_index('Product_ID', inplace=True)
    #peak_products.sort_values('Product_ID', inplace=True)
    #peak_products['frequency'] = peak_products.groupby('Product_ID')['Product_ID'].transform('count')
    peak_products = peak_products.Product_ID.value_counts().reset_index()
    peak_products.columns = ['Product_ID', 'count']
    peak_products.sort_values('Product_ID', inplace=True)
    #peak_products.set_index('Product_ID', inplace=True)
    #peak_products.sort_index(inplace=True)
    print(peak_products)

    non_peak_products = sales_data[sales_data.Ship_Date.dt.month.between(1,9, inclusive=True)]
    #non_peak_products = non_peak_products.Product_ID.value_counts().sort_index()   #.nsmallest(5)
    #non_peak_products['frequency'] = non_peak_products.groupby('Product_ID')['Product_ID'].transform('count')
    #non_peak_products.set_index('Product_ID', inplace=True)
    #non_peak_products.sort_values('Product_ID', inplace=True)
    #non_peak_products['frequency'] = non_peak_products.groupby('Product_ID')['Product_ID'].transform('count')
    non_peak_products = non_peak_products.Product_ID.value_counts().reset_index()
    non_peak_products.columns = ['Product_ID', 'count']
    non_peak_products.sort_values('Product_ID', inplace=True)
    #non_peak_products.set_index('Product_ID', inplace=True)
    #non_peak_products.sort_index(inplace=True)
    print(non_peak_products)
    
    #common_products = peak_products.join(non_peak_products, on='Product_ID')
    #common_products = pandas.concat([peak_products,non_peak_products], axis=1, join='inner')
    common_products = pandas.merge(peak_products, non_peak_products, on=['Product_ID'])
    common_products.columns = ['Product_ID','peak_frequency', 'non_peak_frequency']
    common_products.reset_index(inplace=True, drop=True)
    common_products['frequency_ratio'] = common_products.peak_frequency / common_products.non_peak_frequency
    
    topfive = common_products.nlargest(5, ['frequency_ratio'])['Product_ID'].tolist()

    print(topfive)
    for key in product_data:
        if str(key["Product_Id"]) in topfive:
            print(key["Product_Id"] + ': ' + key["Product_Name"])
    #for index, row in common_products.nlargest(5, ['frequency_ratio']).iterrows():
    #    print(row['Product_ID'], row['frequency_ratio'])



    #common_products = pandas.merge(peak_products, non_peak_products, on='Product_ID', how='inner')
    #print(common_products)
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