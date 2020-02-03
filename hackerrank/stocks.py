from math import inf

stockData = [5,6,8,4,9,10,8,3,6,4]
queries = [3,1,8]
def printData(stockData, queries):
    ans = []
    quer = list(enumerate(stockData)).sort( key = lambda x: x[1])
    for query in queries:
        left = max(quer[query - 1:], key = lambda x: x[0])
        right = min()
    # for query in queries:
    #     target = stockData[query - 1]
    #     flag = True
    #     counter = 1
    #     while flag:
    #         lefty = query - counter - 1; righty = query + counter - 1
    #         if lefty < 0 and righty > len(stockData) - 1:
    #             ans.append(-1)
    #             flag = False
            
    #         if lefty > 0: 
    #             left = stockData[lefty]
    #         else:
    #             left = inf
    #         if not righty > len(stockData) - 1:    
    #             right = stockData[righty]
    #         else:
    #             right = inf
            
    #         # print("Counter", counter, "Query", query)
    #         if left < target:
    #             ans.append(query - counter)
    #             flag = False
    #             break
    #         elif right < target:
    #             ans.append(query + counter)
    #             flag = False
    #             break
    #         counter += 1

    print(ans)
    return ans
printData(stockData, queries)