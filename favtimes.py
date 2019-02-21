from datetime import datetime
from datetime import timedelta
totalmin = int(input())
quot = totalmin // 720
totalmin %= 720
ttimes = datetime.strptime("11:59","%H:%M")
arithtimes = 0
for i in range(totalmin + 1):
    ttimes += timedelta(minutes=1)
    times = ttimes.strftime("%I:%M")
    diff = int(times[4]) - int(times[3])
    if int(times[3]) - int(times[1]) == diff:
        if times[0] == "0" or int(times[1]) - int(times[0]) == diff:
            arithtimes += 1
print(31 * quot + arithtimes)