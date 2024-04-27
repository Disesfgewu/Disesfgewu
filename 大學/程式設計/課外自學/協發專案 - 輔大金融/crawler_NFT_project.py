import urllib.request as req
import json
import requests
NFT = input("Which NFT do you want to get : ")
IP = [ 'sold' , 'price' , 'priceUSD' , 'buyer' , 'seller' ]
IP2 = [ "timeStanp" , "fromDisplay" , "toDisplay" ]
def generate_file_list( file_name ) :
    with open( file_name , "r" , encoding = "utf-8" ) as file :
        get_imformation = file.read().splitlines()
    return get_imformation
# start = int(input("Which number do you want to get : "))
# end = start
file_name_list = [ "BAYC_High.txt" , "BAYC_Low.txt" , "MAYC_High.txt" , "MAYC_Low.txt" ]
for file_name in range( len(file_name_list) ) :
    for start in generate_file_list( file_name_list[ file_name ] ) :
        file = NFT + "_sales2_" + start + ".txt"
        f = open(file, "w+", encoding='utf-8')
        url = ""
        print( "start get sales" )
        if file_name == 0 or file_name == 1 :
            url = "https://web-api.cryptoslam.io/api-gateway/v1/mint/bored-ape-yacht-club/token/" + start + "/sales"
        request = req.Request(url, headers={
                "User-Agent": "Mozilla/5.0 (iPhone; CPU iPhone OS 13_2_3 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/13.0.3 Mobile/15E148 Safari/604.1"
            })
        print( url )
        r = requests.get(url)
        if r.status_code != 200:
            continue
        with req.urlopen(request) as response:
            data = json.load(response)
        for get in data:
            f.write( "sold " + str(get['timeStamp']) + " " )
            f.write( "price " + str(get['price'] )+ " " )
            f.write( "priceUSD " + str(get['priceUSD']) + " " )
            f.write( "buyer " + str(get['buyerDisplay']) + " " )
            f.write( "seller " + str(get['sellerDisplay']) + " " )
            f.write( '\n' )
        # for i in range( int(start) , int(start)+1):
        #     if NFT == "Mutant":
        #         url = "https://web-api.cryptoslam.io/api-gateway/v1/mint/mutant-ape-yacht-club/token/" + str(i) + "/sales"
        #     else:
        #         url = "https://web-api.cryptoslam.io/api-gateway/v1/mint/bored-ape-yacht-club/token/" + str(i) + "/sales"
        # request = req.Request(url, headers={
        #     "User-Agent": "Mozilla/5.0 (iPhone; CPU iPhone OS 13_2_3 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/13.0.3 Mobile/15E148 Safari/604.1"
        # })
            # r = requests.get(url)
            # if r.status_code != 200:
            #     continue
        #     if i != start:
        #         f.write('\n')
        #     if NFT == "Mutant" :
        #         print("mutant-ape-yacht-club " + str(i) + " is sccessful")
        #         f.write( "mutant-ape-yacht-club " + str(i) + '\n' )
        #     else :
        #         print("bored-ape-yacht-club " + str(i) + " is sccessful")
        #         f.write( "bored-ape-yacht-club " + str(i) + '\n' )
            # with req.urlopen(request) as response:
            #     data = json.load(response)
            
            # for get in data:
            #     f.write( "sold " + str(get['timeStamp']) + " " )
            #     f.write( "price " + str(get['price'] )+ " " )
            #     f.write( "priceUSD " + str(get['priceUSD']) + " " )
            #     f.write( "buyer " + str(get['buyerDisplay']) + " " )
            #     f.write( "seller " + str(get['sellerDisplay']) + " " )
            #     f.write( '\n' )
        f.close()
        
# print( "start get tranfers" )
# url = ""
# file2 = NFT + "_transfers_" + str(start) + "_" + ".txt"
# f2 = open(file2, "w+", encoding='utf-8')
# for i in range(start, end+1):
#     if NFT == "Mutant":
#         url = "https://web-api.cryptoslam.io/api-gateway/v1/mint/mutant-ape-yacht-club/token/" + \
#             str(i) + "/transfers"
#     else:
#         url = "https://web-api.cryptoslam.io/api-gateway/v1/mint/bored-ape-yacht-club/token/" + \
#             str(i) + "/transfers"
#     request = req.Request(url, headers={
#         "User-Agent": "Mozilla/5.0 (iPhone; CPU iPhone OS 13_2_3 like Mac OS X) AppleWebKit/605.1.15 (KHTML, like Gecko) Version/13.0.3 Mobile/15E148 Safari/604.1"
#     })
#     r = requests.get(url)
#     if r.status_code != 200:
#         continue
#     if i != start:
#         f2.write('\n')
#     if NFT == "Mutant" :
#         print("mutant-ape-yacht-club " + str(i) + " is sccessful")
#         f2.write( "mutant-ape-yacht-club " + str(i) + '\n' )
#     else :
#         print("bored-ape-yacht-club " + str(i) + " is sccessful")
#         f2.write( "bored-ape-yacht-club " + str(i) + '\n' )
#     with req.urlopen(request) as response:
#         data = json.load(response)
#     for get in data:
#         f2.write( "transfered " + str( get['timeStamp']) + " " )
#         f2.write( "from " + str( get['fromDisplay']) + " " )
#         f2.write( "to " + str( get['toDisplay']) + " " )
#         f2.write( '\n' )
# f2.close()