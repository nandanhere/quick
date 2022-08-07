<%@ page language="java" contentType="text/html; charset=ISO8859-1" pageEncoding="ISO-8859-1" %>
    <!DOCTYPE html>
    <html>
    <head>
        <meta charset="ISO-8859-1">
        <title>Insert title here</title>
    </head>

    <body>
        <div align='center'>
            <p>Updated Database:</p>
            <pre>${requestScope["data"]}</pre>
            <br><br><br><br>
            <form action='GetServlet' method='post'>
                Get Current Database data:
                <input type='submit' value='GetData' />
            </form>
        </div>
        </body>
        </html>