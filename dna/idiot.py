import random
import matplotlib.pyplot as plt

def main():
    win_loss = [0, 0]
    trial = 0
    while trial < 10000:
        trial += 1
        winORloss = play300()
        win_loss[winORloss] += 1
    print (win_loss)
    plt.figure(figsize=(5,5))
    plt.pie(win_loss, labels=['win', 'loss'])
    plt.legend()    
    plt.show()

def play300():
    money = 10
    winloss = 0
    for i in range(1, 300):
        point = random.randint(1, 6)
        if point == 1:
            money = money * 0.5
        elif point == 6:
            money = money * 2
        else:
            money = money * 1.05
    if money > 10:
        winloss = 0
    else:
        winloss = 1
    return winloss
main()
