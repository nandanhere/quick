<%@ page language="java" contentType="text/html; charset=ISO8859-1" pageEncoding="ISO-8859-1" %>
        <!DOCTYPE html>
        <html>

        <head>
            <meta charset="ISO-8859-1">
            <title>Insert title here</title>
        </head>

        <body>
            <div align='center'>
                <p>Database data:</p>
                <pre>${requestScope["data"]}</pre>
                <form action='GetServlet' method='get'>
                    Update Database: <input type='submit' value='Add data' /> </form>
            </div>
        </body>

        </html>