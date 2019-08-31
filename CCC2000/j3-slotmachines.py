bank = int(input())

pastslot = {}
pastslot.update({35:int(input())})
pastslot.update({100:int(input())})
pastslot.update({10:int(input())})

plays = 0

while bank > 0:
    acoins = (pastslot[35] + bank/3) // 35
    bcoins =  (pastslot[100] + bank/3) // 100
    ccoins = (pastslot[10] + bank/3) // 10
    summed = 30*acoins + 60*bcoins + 9*ccoins
    plays += bank
    for freq, val in pastslot.items():
        pastslot[freq] += bank/3
        pastslot[freq] = pastslot[freq] % freq
    # print(pastslot)
    bank = summed
    
    # print("acoins: {}, bcoins: {}, ccoins: {}, bank: {}, plays: {}".format(acoins, bcoins, ccoins, bank, plays))
print("Martha plays {} times before going broke.".format(int(plays)))