package main

import (
	"fmt"
	"strings"
)

type Product struct{
	name string 
	price int64
}

func main()  {
	fmt.Println("Hello world! ")
	var name string=""
	fmt.Scanf("%s",&name)
	fmt.Printf("Hello %s world! %d \n",name,90)
	var cnt int=3
	var i int=0 
	for i<cnt{
		fmt.Println(i);
		i++;
	}
	fmt.Println("============")
	for j := 0; j < 3; j++ {
		fmt.Println(j)
		
	}

	arr := []string{"satyam","rahul","deepak"}   //Slice i-e array without any size
	arr = append(arr, "ranjit","abhishek")
	fmt.Println(arr)
	for index,value := range arr{
		fmt.Printf("%d. %s \n",index,value)
	}

	var arr1 [5]int    //array
	for i := 0; i<5; i++{
		// fmt.Scanf("%d",&arr1[i])
	}
	fmt.Println(arr1[3])
	str := strings.Split(name, "")
	str[0] = "Q"
	fmt.Println(str)
	name = strings.Join(str,"")
	println(name)

	arr4 := [2][]int{{12,34,45},{54,67,78}}
	fmt.Println(arr4)

	arr5 := []int{1,2,3}
	var ptr* []int
	ptr = &arr5
	fmt.Println(*ptr)

	mp := map[int][]int{
		0: {1, 2},
	}
	mp[1] = []int{3,4,6}
	mp[2] =[]int{4,5,6,7}
	delete(mp,0)
	fmt.Println(mp)
	fmt.Println(mp[2])

	for key,value := range mp{
		fmt.Printf("%d -> %v \n",key,value)
	}
	var product [2]Product
	product[0] = Product{"soap",10}
	product[1] = Product{"maggi",15}
	fmt.Println(product)
	
	num := 109
	var num1* int
	num1 = &num
	*num1 = *num1*10
	fmt.Printf("num = %d , num1 = %v ",num,*num1)

	arr6 := []int{10,20,30,40}
	code,status,sum := solve(10,20,arr6,23,45,67)
	fmt.Printf("%d %s \n",code,status)
	fmt.Printf("Sum = %d\n",sum)
	for _,val := range arr6{
		fmt.Printf("%d, ",val)
	}


	p := Product{"Mobile",12000}
	p.display()
	
}

func solve(a int,b int,arr []int,other ...int) (int,string,int) {
	fmt.Println("Solve called")
	arr[0] = 987
	fmt.Printf("length = %d \n",len(arr))
	sum := a+b
	for _,num := range other{
		sum+=num
	}
	return 200,"ok",sum
}



// In Go, a receiver function (also called a method) is a function 
// that is attached to a specific type (struct, slice, map, or even basic types like int). 
// It allows you to call the function using the dot notation (obj.Method()).
/*
func (receiver ReceiverType) MethodName(parameters) returnType {
    Method logic
}
*/

func (p Product) display(){
	fmt.Printf("\nProduct Name = %s \t Price = Rs. %d\n",p.name,p.price)
}