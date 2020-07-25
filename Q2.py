# -*- coding: utf-8 -*-
import time
import math
class Cache:
    def __init__(self , cache_size):
        self.cache_size = cache_size
        #declare array with the size I want
        self.array = [None]*cache_size
        self.hash_map = dict()

    def is_array_full(self):
        check = 0

        for i in range(0,len(self.array)):
            if (self.array[i] == None):
                check = check + 1
        
        #if check = 0, mean no None for new data, return true
        if (check == 0):
            return True

    
    def put(self, key, value, weight, last_access_time):

        if key not in self.hash_map:
            if self.is_array_full():

                score = [None]*len(self.array)
                #check the time
                current_time = time.time()
                #find the score
                for i in range(0,len(self.array)):
                    if (current_time != self.hash_map[self.array[0]][2]):
                        score[i] = self.hash_map[self.array[0]][1]/math.log(current_time-self.hash_map[self.array[0]][2])
                    else :
                        score[i] = self.hash_map[self.array[0]][2]/(-100)
                min_score = min(score)
                
                for i in range(0,len(self.array)):
                    if(min_score == score[i]):
                        flag = i
                
                del self.hash_map[self.array[flag]]
                self.hash_map[key] = [value, weight, current_time]
                self.array[flag] = key
            
            else:
                current_time = time.time()
 
                self.hash_map[key]= [value, weight, current_time]
                for i in range(0,len(self.array)):
                    #find a None for saving data
                    if (self.array[i] == None):

                        self.array[i] = key
                        break

    def get(self, key):
        if key not in self.hash_map:
            return -1
        else :
            self.hash_map[key][2] = time.time()
            return self.hash_map[key][0:1]
            
if __name__ == '__main__':
    #set the size of cache, in this case I set to 3
    cache = Cache(3)
    
    cache.put('key1', 1,1,time.time())
    cache.put('key2', 2,0.1,time.time())
    cache.put('key3', 3,0.01,time.time())
    cache.put('key4', 4,2,time.time())
    

    print(cache.get('key1'))
    print(cache.get('key2'))
    print(cache.get('key3'))
    print(cache.get('key4'))
        
    