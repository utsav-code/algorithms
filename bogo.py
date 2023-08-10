from random import shuffle

def bogosort(data):
    while not all(data[i] <= data[i+1] for i in range(len(data)-1)):
        shuffle(data)
    return data




