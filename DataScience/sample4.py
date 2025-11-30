print("Exception Handling in Python")
class CustomError(Exception):
    def __init__(self, message):
        self.message = message
if __name__ == "__main__":
    try:
        # val= 5/0
        raise CustomError("This is a custom error message.")
    except ZeroDivisionError as e:
        print(f"Caught an exception: {e}")
    except CustomError as ce:
        print(f"Caught an error: {ce.message}")
    else:
        print("No exceptions occurred.")
    finally:
        print("Execution completed.")


# BaseException
#   ├── Exception
#   │   ├── ArithmeticError
#   │   ├── AssertionError
#   │   ├── AttributeError
#   │   ├── LookupError (IndexError, KeyError)
#   │   ├── NameError
#   │   ├── TypeError
#   │   ├── ValueError
#   │   └── ... (many more)
#   ├── SystemExit
#   ├── KeyboardInterrupt
#   └── GeneratorExit 