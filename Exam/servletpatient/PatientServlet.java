import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet("/PatientServlet")
public class PatientServlet extends HttpServlet {

  private static final long serialVersionUID = 1L;

  public PatientServlet() {
    super(); // TODO Auto-generated constructor stub
  }

  protected void doGet(
    HttpServletRequest request,
    HttpServletResponse response
  )
    throws ServletException, IOException {}

  protected void doPost(
    HttpServletRequest request,
    HttpServletResponse response
  )
    throws ServletException, IOException {
    String name = request.getParameter("name");
    String age = request.getParameter("age");
    String date = request.getParameter("date");
    String cause = request.getParameter("cause");
    String doctor = request.getParameter("doc");
    String treat = request.getParameter("treat");
    String s = "";
    //System.out.println(s);
    try {
      Class.forName("com.mysql.jdbc.Driver");
      Connection con = DriverManager.getConnection(
        "jdbc:mysql://localhost:3306/java",
        "root",
        "root"
      );
      String updateDB = "insert into PatientRecords values(?,?,?,?,?,?);";
      PreparedStatement ps = con.prepareStatement(updateDB);
      ps.setString(1, name);
      ps.setString(2, age);
      ps.setString(3, date);
      ps.setString(4, cause);
      ps.setString(5, doctor);
      ps.setString(6, treat);
      int i = ps.executeUpdate();
      System.out.println("Rows inserted: " + i);
      s =
        name +
        "\n" +
        age +
        "\n" +
        date +
        "\n" +
        cause +
        "\n" +
        doctor +
        "\n" +
        treat +
        "\n" +
        i;
    } catch (Exception e) {
      System.out.println(e);
    }
    request.setAttribute("data", s);
    request.getRequestDispatcher("/view.jsp").forward(request, response);
  }
}
