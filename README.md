# Student Information Management in C

এটি একটি simple C program, যেখানে user একাধিক student-এর **Name, Roll এবং CGPA** input দিতে পারে। Program-টি সেই তথ্য একটি text file-এ save করে এবং পরে file থেকে data পড়ে আবার screen-এ দেখায়।

এই program-টি মূলত **Structure এবং File Handling in C** practice করার জন্য তৈরি করা হয়েছে।

---

## 📌 Program কী করে?

Program-টি নিচের কাজগুলো করে:

1. কতজন student-এর তথ্য নেওয়া হবে তা input নেয়।
2. প্রতিটি student-এর:

   * Name
   * Roll
   * CGPA
     input নেয়।
3. `struct` ব্যবহার করে student-এর information store করে।
4. `student-info.txt` file-এ information save করে।
5. File-টি আবার read mode-এ open করে।
6. File-এর ভিতরের data console-এ display করে।

---

## 🧠 Code Explanation

### 1. Structure তৈরি করা

```c
typedef struct{

    char name[50];
    int roll;
    float cgpa;

}student;
```

এখানে `student` নামে একটি user-defined data type তৈরি করা হয়েছে।

একজন student-এর তিনটি information থাকবে:

```text
name → Student-এর নাম
roll → Roll number
cgpa → CGPA
```

`char name[50]` ব্যবহার করার কারণে student-এর নাম string হিসেবে রাখা যায়।

---

### 2. File Pointer তৈরি করা

```c
FILE *fp;
```

`fp` হলো একটি **file pointer**।

এটি file-এর সাথে কাজ করার জন্য ব্যবহার করা হয়।

---

### 3. File Write Mode-এ Open করা

```c
fp = fopen("student-info.txt", "w");
```

এখানে `fopen()` দিয়ে `student-info.txt` file open করা হয়েছে।

`"w"` এর অর্থ **write mode**।

অর্থাৎ file-এর মধ্যে data লেখা যাবে।

---

### 4. Student-এর সংখ্যা নেওয়া

```c
int n;

printf("Enter Number of Student: ");
scanf("%d", &n);
```

User কতজন student-এর information দিতে চায়, সেই সংখ্যা `n`-এ রাখা হচ্ছে।

যেমন:

```text
Enter Number of Student: 3
```

তাহলে ৩ জন student-এর information নেওয়া হবে।

---

### 5. Structure-এর Array তৈরি করা

```c
student std[n];
```

এখানে `student` structure-এর একটি array তৈরি করা হয়েছে।

যদি:

```text
n = 3
```

হয়, তাহলে:

```text
std[0] → Student 1
std[1] → Student 2
std[2] → Student 3
```

এভাবে একাধিক student-এর information রাখা যায়।

---

### 6. Student-এর Information Input নেওয়া

```c
for(int i = 0; i < n; i++){

    printf("Enter info of Student: %d\n", i+1);

    printf("Name: ");
    scanf(" %[^\n]", std[i].name);

    printf("Roll: ");
    scanf("%d", &std[i].roll);

    printf("CGPA: ");
    scanf("%f", &std[i].cgpa);
}
```

এখানে `for` loop ব্যবহার করে প্রতিটি student-এর information নেওয়া হচ্ছে।

### Full Name নেওয়ার বিষয়টি

```c
scanf(" %[^\n]", std[i].name);
```

এখানে `%s` ব্যবহার করা হয়নি।

কারণ `%s` space পর্যন্ত input নেয়।

যেমন:

```text
Faysal Ahmed
```

`%s` ব্যবহার করলে শুধু:

```text
Faysal
```

নিত।

কিন্তু:

```c
%[^\n]
```

ব্যবহার করলে Enter চাপার আগ পর্যন্ত পুরো line input নেয়।

তাই:

```text
Faysal Ahmed
```

পুরোটাই `name`-এ store হবে।

---

## 💾 7. File-এ Data লেখা

```c
for(int i = 0; i < n; i++){

    fprintf(fp, "\nName: %s \nRoll: %d CGPA: %.2f\n",
            std[i].name,
            std[i].roll,
            std[i].cgpa);
}
```

এখানে `fprintf()` ব্যবহার করে student-এর information file-এ লেখা হচ্ছে।

সাধারণত:

```c
printf()
```

দিয়ে console-এ output দেখাই।

কিন্তু:

```c
fprintf()
```

ব্যবহার করে file-এর মধ্যে output লেখা যায়।

এখানে:

```text
%s  → Name
%d  → Roll
%.2f → CGPA
```

`%.2f` ব্যবহার করার কারণে CGPA দুই decimal place-এ save হবে।

যেমন:

```text
3.75
```

---

## 🔒 8. File Close করা

```c
fclose(fp);
```

Data লেখার কাজ শেষ হওয়ার পরে file close করা হয়েছে।

File নিয়ে কাজ শেষ হলে `fclose()` ব্যবহার করা ভালো practice।

---

## 📖 9. File আবার Read Mode-এ Open করা

```c
fp = fopen("student-info.txt", "r");
```

এবার একই file আবার open করা হয়েছে।

এখানে:

```text
"r" → Read Mode
```

অর্থাৎ এখন file থেকে data পড়া হবে।

---

## 🔤 10. File থেকে Data পড়া

```c
char ch;

while((ch = fgetc(fp)) != EOF){
    printf("%c", ch);
}
```

এখানে `fgetc()` ব্যবহার করে file থেকে **একটি করে character** পড়া হচ্ছে।

ধরো file-এর মধ্যে আছে:

```text
Name: Faysal
```

তাহলে `fgetc()` এভাবে পড়বে:

```text
N → a → m → e → : → F → a → y → s → a → l
```

প্রতিটি character `ch` variable-এ রাখা হয়।

তারপর:

```c
printf("%c", ch);
```

দিয়ে screen-এ print করা হয়।

### `EOF` কী?

`EOF` এর অর্থ:

**End Of File**

অর্থাৎ file-এর শেষ পর্যন্ত পড়তে থাকবে।

যখন file-এর শেষ পাওয়া যাবে, তখন:

```c
fgetc(fp) == EOF
```

হবে এবং loop বন্ধ হয়ে যাবে।

---

## 🔄 Complete Flow

Program-টির পুরো process:

```text
User Input
    ↓
Structure Array
    ↓
Write Data to File
    ↓
fclose()
    ↓
Open File in Read Mode
    ↓
Read Character by Character
    ↓
Display on Console
```

---

## 📚 Main Functions Used

| Function    | কাজ                          |
| ----------- | ---------------------------- |
| `fopen()`   | File open করে                |
| `fclose()`  | File close করে               |
| `fprintf()` | File-এ formatted data লেখে   |
| `fgetc()`   | File থেকে একটি character পড়ে |
| `scanf()`   | User-এর কাছ থেকে input নেয়   |
| `printf()`  | Console-এ output দেখায়       |

---

## 🎯 Concepts Practiced

এই program-এর মাধ্যমে নিচের C concepts practice করা হয়েছে:

* `struct`
* `typedef`
* Array of Structures
* `for` loop
* String Input
* File Handling
* File Writing
* File Reading
* `FILE` pointer
* `EOF`

---

## 📝 Note

এই program-এ file-এর data **character by character** পড়া হয়েছে `fgetc()` ব্যবহার করে।

এটি file reading-এর basic concept বোঝার জন্য একটি simple implementation।
