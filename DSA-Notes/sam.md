```md
Class Description:
    1. The Card class represents an ATM card with a card number and PIN.
    2. The Account class represents a bank account with an account number and balance. It provides methods to debit and credit the account balance.
    3. The Transaction class is an abstract base class for different types of transactions, such as withdrawal and deposit. It is extended by WithdrawalTransaction and DepositTransaction classes.
    4. The BankingService class manages the bank accounts and processes transactions. It uses a thread-safe ConcurrentHashMap to store and retrieve account information.
    5. The CashDispenser class represents the ATM's cash dispenser and handles the dispensing of cash. It uses synchronization to ensure thread safety when dispensing cash.
    6. The ATM class serves as the main interface for ATM operations. It interacts with the BankingService and CashDispenser to perform user authentication, balance inquiry, cash withdrawal, and cash deposit.
    7. The ATMDriver class demonstrates the usage of the ATM system by creating sample accounts and performing ATM operations.
```


## Designing a Parking Lot System
#### Requirements:
1. The parking lot should have multiple levels, each level with a certain number of parking spots.
2. The parking lot should support different types of vehicles, such as cars, motorcycles, and trucks.
3. Each parking spot should be able to accommodate a specific type of vehicle.
4. The system should assign a parking spot to a vehicle upon entry and release it when the vehicle exits.
5. The system should track the availability of parking spots and provide real-time information to customers.
6. The system should handle multiple entry and exit points and support concurrent access.

#### Classes, Interfaces and Enumerations
1. The ParkingLot class follows the Singleton pattern to ensure only one instance of the parking lot exists. It maintains a list of levels and provides methods to park and unpark vehicles.
2. The Level class represents a level in the parking lot and contains a list of parking spots. It handles parking and unparking of vehicles within the level.
3. The ParkingSpot class represents an individual parking spot and tracks the availability and the parked vehicle.
4. The Vehicle class is an abstract base class for different types of vehicles. It is extended by Car, Motorcycle, and Truck classes.
5. The VehicleType enum defines the different types of vehicles supported by the parking lot.
6. Multi-threading is achieved through the use of synchronized keyword on critical sections to ensure thread safety.
7. The Main class demonstrates the usage of the parking lot system.




## Designing a Vending Machine
#### Requirements
1. The vending machine should support multiple products with different prices and quantities.
2. The machine should accept coins and notes of different denominations.
3. The machine should dispense the selected product and return change if necessary.
4. The machine should keep track of the available products and their quantities.
5. The machine should handle multiple transactions concurrently and ensure data consistency.
6. The machine should provide an interface for restocking products and collecting money.
7. The machine should handle exceptional scenarios, such as insufficient funds or out-of-stock products.

#### Classes, Interfaces and Enumerations
    The Product class represents a product in the vending machine, with properties such as name and price.
    The Coin and Note enums represent the different denominations of coins and notes accepted by the vending machine.
    The Inventory class manages the available products and their quantities in the vending machine. It uses a concurrent hash map to ensure thread safety.
    The VendingMachineState interface defines the behavior of the vending machine in different states, such as idle, ready, and dispense.
    The IdleState, ReadyState, and DispenseState classes implement the VendingMachineState interface and define the specific behaviors for each state.
    The VendingMachine class is the main class that represents the vending machine. It follows the Singleton pattern to ensure only one instance of the vending machine exists.
    The VendingMachine class maintains the current state, selected product, total payment, and provides methods for state transitions and payment handling.
    The VendingMachineDemo class demonstrates the usage of the vending machine by adding products to the inventory, 
    selecting products, inserting coins and notes, dispensing products, and returning change.

```md
# LeetCode - 187
The DNA sequence is composed of a series of nucleotides abbreviated as 'A', 'C', 'G', and 'T'.

For example, "ACGAATTCCG" is a DNA sequence.
When studying DNA, it is useful to identify repeated sequences within the DNA.

Given a string s that represents a DNA sequence, return all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule. You may return the answer in any order.
```
```python
def polyHash(s: str):
    p = 31
    m = 10**10 + 7
    prefixHash = [0] * (len(s) + 1)
    pow_p = [1] * (len(s) + 1)
    
    for i in range(1, len(s) + 1):
        pow_p[i] = (pow_p[i-1] * p) % m
        prefixHash[i] = (prefixHash[i-1] + (ord(s[i-1]) - ord('A') + 1) * pow_p[i-1]) % m
    
    return prefixHash, pow_p

def findRepeatedDnaSequences(s: str):
    if len(s) < 10:
        return []
    
    prefixHash, pow_p = polyHash(s)
    mp = {}
    res = set()
    m = 10**10 + 7
    
    for i in range(len(s) - 9):
        hash_val = (prefixHash[i+10] - prefixHash[i]) % m
        hash_val = (hash_val * pow_p[len(s) - i]) % m  # Normalize
        
        substring = s[i:i+10]
        if hash_val in mp:
            res.add(substring)
            mp[hash_val] += 1
        else:
            mp[hash_val] = 1
    
    return list(res)
```