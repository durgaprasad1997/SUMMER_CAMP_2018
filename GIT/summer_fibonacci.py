# import sys
# from contextlib import contextmanager
#
# @contextmanager
# def ContextManager():
#     try:
#         print("in cintext")
#         yield(20)
#
#     finally:
#         print("exit")
#         raise StopIteration("stop")
#
#
#
# def test():
#     with ContextManager() as x:
#         print("in body")
#         raise StopIteration("dfvdf")
#         raise ValueError("value error")

#
# def blah(func):
#     def innerdec():
#         print("inside in func")
#         return func()
#     print("entry dec")
#     return innerdec
#
#
#
# @blah
# def testdec():
#     print("inside testdoc")
#
# if __name__=="__main__":
#    testdec()
import time
dict_count=dict()
dict_time=dict()


def mainwrapper(recursive=True):
    def wrapper(func):
        def inner(*args,**kwargs):
            result = func(*args, **kwargs)

            initial=time.time()

            if(recursive==False):
                dict_count[0]=1
                dict_time[args[0]]=initial


            else:
                if(args[0] in dict_count.keys()):
                    dict_count[args[0]]=dict_count[args[0]]+1
                    dict_time[args[0]] += initial
                else:
                    dict_count[args[0]] = 1
                    dict_time[args[0]] = initial


            return result


        return inner
    return wrapper



@mainwrapper(recursive=True)
def fibonacci(n):
    if(n==1):
        return 1
    if(n==2):
        return 1
    return fibonacci(n-1)+fibonacci(n-2)



if __name__=="__main__":
    print(fibonacci(5))
    print(sum(dict_count.values()))
    print(dict_time)

