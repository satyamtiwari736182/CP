def sample(fun):
    print("wrap function executed")
    def wrapper():
        fun()
    return wrapper
    

@sample
def template():
    print("template function executed")

template()

# sample(template)
