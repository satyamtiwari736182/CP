import sample3
def sample(fun):
    print("wrap function executed")
    def wrapper():
        fun()
    return wrapper
    

@sample
def template():
    print("template function executed")

# template()
# temp = template()
# temp()
# sample(template)()

# !  Decorators run at function definition time, not at function call time.
''' As soon as python sees the @sample decorator above the template function, it immediately calls sample(template).
# This means that "wrap function executed" is printed right away, and template is replaced by the wrapper function returned by sample.
#? Later, when template() is called, it actually calls the wrapper function, which in turn calls the original template function. '''
