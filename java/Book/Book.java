import java.util.*;
class Book
{
String title,author, publisher;
double price;
Book(String title,String author,String publisher,double price)
{ this.title=title;
 this.author=author;
 this.publisher=publisher;
 this.price = price;
}
public String toString()
{
String str= "Book has "+title+"title "+"whose author is "+author;
str+="\n Book is published by "+publisher;
str+="\n Price is= "+price;
return str;
}
}