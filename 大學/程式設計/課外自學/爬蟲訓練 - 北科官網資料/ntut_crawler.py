import bs4
import requests


def store_txt_file(content, txt):
    f = open(txt, "a", encoding="utf-8")
    f.write(content)
    f.close()


def clearing(txt):
    f = open(txt, 'w')
    f.close()


def getting(url):
    result = requests.get(url)
    if result.status_code == 200:
        result = bs4.BeautifulSoup(result.text, "lxml")
    else:
        return False
    return result


clearing("content.txt")

result = getting("https://www.ntut.edu.tw/app/showmodule.php?Mobile=1&rs=sajaxSubmit&O=1000&F=/0/1000/modules/mobile_rcg_mstr/11/mobile_rcg_mstr-11.htm.zh-tw&Mo=10827&Type=mobile_rcg_mstr&Nbr=11&Seq=11&Cg=cmb")
get = result.select("p.more a")

print(get[0]['href'])

result = getting(get[0]['href'])
get = result.select("div.d-txt div.mtitle a")

for i in get:
    store_txt_file(i['title']+'\n', "content.txt")

inital = get[0]['href']
"""
for page in range(2, 10):
    print(inital[0:38] + str(page) + inital[40:len(inital)])
    result = getting(inital[0:38] + str(page) + inital[40:len(inital)])
    if result == False:
        continue
    get = result.select("div.d-txt div.mtitle a")

    for i in get:
        store_txt_file(i['title']+'\n', "content.txt")
        print(i['title'])
"""
