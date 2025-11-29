function Student(name,city){
    // name;city;
    this.name = name;
    this.city=city;
    
    show=()=>{
        console.log(this)
        console.log("hello world");
    }
    
}

Student.prototype.show2=()=>{
    console.log(this)
    console.log("hello world ji how are you?");
}


function School(schoolName,schoolAddress){
    Student.call(this,"Satyam","WB");
    this.schoolName = schoolName;
    this.schoolAddress = schoolAddress;
    
}
School.prototype.showSchool=()=>{
    console.log(this);
    console.log("my school");
}

// School.prototype=Object.create(Student);

const st1=new Student("satyam","jaigaon");
// // st1.prototype.state="WB";
console.log(st1)
sh=Student.show;
console.log(sh)
Object.prototype.chk=function(){
    console.log(this)
    console.log("I am Object checking")
}
const sc1=new School("BD school","Jaigaon");
console.log(sc1);
// sc1.showSchool();
// sc1.show2();







// class Student{
//     // name;city;
//     constructor(name,city){
//         this.name = name;
//         this.city=city;
//     }
//     show=()=>{
//         console.log(this)
//         console.log("hello world");
//     }
//     show2(){
//         console.log(this)
//         console.log("hello world ji how are you?");
//     }
// }


// class School extends Student{
//     constructor(schoolName,schoolAddress){
//         super("Satyam","WB");
//         this.schoolName = schoolName;
//         this.schoolAddress = schoolAddress;
//     }
//     static showSchool(){
//         console.log(this);
//         console.log("my school");
//     }
// }
// const st1=new Student("satyam","jaigaon");
// // st1.prototype.state="WB";
// console.log(st1)
// st1.show();
// // Object.prototype.chk=function(){
// //     console.log(this)
// //     console.log("I am Object checking")
// // }
// // const sc1=new School("BD school","Jaigaon");
// // console.log(sc1);
// // School.showSchool();
// // sc1.show();