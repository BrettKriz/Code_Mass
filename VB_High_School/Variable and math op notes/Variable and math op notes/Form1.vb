Public Class Form1

    Private Sub Label1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Label1.Click

    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Variables are used to hold a value in a program.
        'The value of the variable can change over time.
        'Variables are always given a name and must be declared
        'before use.

        'Example:
        Dim length As Double
        Dim width As Double

        'I use Dim to create a variable
        'I must provide a name (I choose) and a data type

        'Legal names for Variables
        '1. Containe no spaces or punctuations
        '2. Contain only letters and numbers
        '3. Must start w/ letter
        '4. Underscores are ok
        '5. Can't be reserved (BLUE) words like sub, Double, etc

        'Other types of data
        '1. Integer (pos/neg whole #s
        '2. Double (Pos/neg decimal numbers)
        '3. String (Text)

        'Get lengtyh and width from the user
        'i.e fill our variables with a value
        length = TextBox1.Text
        width = TextBox2.Text

        'Calculate (+, -, *, /, ^, () ) VB knows the
        'Order of operations
        Dim area As Double
        area = length * width

        'FORMATTING OUTPUT (pick 1 of the 3)
        '***********************************

        'Out put the results to the user
        'w/no formatting
        'Label4.Text = area

        'Output formatted to 3 decimal places
        Label4.Text = Format(area, "##.###")

        'output as currency
        'Label4.Text = Format(area, "Currency")

        'FINAL THOUGHT:
        'The order of the lines of your code matters!
        'They execute from top to bottom, and one calculation
        'Might depend on others that need to go first

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'Absolute value
        Dim x As Integer
        x = -10
        Label4.Text = Math.Abs(x)
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        'Square Root
        Dim x As Integer
        x = 25
        Label4.Text = Math.Sqrt(x)
    End Sub
End Class
