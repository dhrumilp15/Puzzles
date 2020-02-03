import re

def search(start, dest, adjdic):
    visited = set()
    queue = []
    queue.append(start)
    visited.add(start)
    flag = False
    while queue:
        linky = queue.pop(0)
        if linky in adjdic:
            if dest in adjdic[linky]:
                flag = True
            for link in adjdic[linky]:
                if link not in visited:
                    queue.append(link)
                    visited.add(link)
    return flag

sites = int(input())
adjdic = {}

for site in range(sites):
    origin = input()
    adjdic.update({origin:()})
    currline = ""
    while currline != "</HTML>":
        currline = input()
        links = re.findall('<A HREF="(.*?)">', currline)
        if len(links) > 0:
            for link in links:
                adjdic[origin] += link,
                print("Link from {} to {}".format(origin, link))
while True:
    start = input()
    if start == "The End":
        break
    dest = input()
    if search(start, dest, adjdic):
        print("Can surf from {} to {}.".format(start, dest))
    else:
        print("Can't surf from {} to {}.".format(start, dest))