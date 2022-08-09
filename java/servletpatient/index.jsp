<!DOCTYPE html>
<html>

<head>
    <meta charset="ISO-8859-1">
    <title>Insert Patient Details</title>
</head>

<body>
    <div align='center'>
        <form action='PatientServlet' method='post'>
            Name: <input type='text' name='name' /><br><br> Age: <input type='number' name='age' /><br><br> Date of
            Admission: <input type='date' name='date' /><br><br> Cause of Admission: <input type='text'
                name='cause' /><br><br> Doctor Diagnosed: <input type='text' name='doc' /><br><br> Treatment Proposed:
            <input type='text' name='treat' /><br><br> <input type="submit" value='update' /> </form> <br><br><br><br>
        <form action='GetServlet' method='post'>
            Get Current Database data: <input type='submit' value='GetData' />
        </form>
    </div>
</body>

</html>

      