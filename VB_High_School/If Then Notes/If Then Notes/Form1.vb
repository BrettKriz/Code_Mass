Public Class Form1
    'put global variables here
    Dim example As Integer 'this is global

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Relational operators are used to compare two
        'values with a result of true or false (BOOLEAN)

        'Relational operators: <, >, =, <>, <=, >=
        '       Dont reverse positions of    ^   ^

        Label2.Text = 5 > 2
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'If/Else If/Else
        '***************

        'In addition to if and else, the optinal else if
        'clause allows us to check additonal conditions

        'VB will work from top to bottom and will stop as
        'soon as it finds one condition that is true

        'You can have 0 to infinite else ifs

        Dim temp As Integer
        temp = TextBox1.Text

        If temp > 1200 Then
            Label2.Text = "Warning - Death? lol"
        ElseIf temp > 1000 Then
            Label2.Text = "Warning - temp too high"
        ElseIf temp > 800 Then
            Label2.Text = "Getting warmer..."
        Else
            Label2.Text = "Temp is OK"
        End If

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        'If- Then
        '********

        'If-thens use boolean expression to make a choice
        'and then act based on that choice
        Dim temp As Integer
        temp = TextBox1.Text

        If temp > 1000 Then
            Label2.Text = "Warning - Temp is too high!"
        End If
    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        'The LOGICAL OPERATORS let you look at two
        'or more conditions in a single if

        Dim temp As Integer
        temp = TextBox1.Text

        '"And" checks to see if both (ALL) conditions
        'are true
        If temp > 0 And temp <= 800 Then
            MsgBox("Temp OK")
        End If

        '"OR" checks to see if any of the conditions
        'are true
        If temp < 0 Or temp > 2000 Then
            MsgBox("Invalid Input")
        End If

    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        'If/Else
        '*******

        'The else clause represents an alternative action
        'for when the boolean expression is false
        'You can only have one 'else'
        Dim temp As Integer
        temp = TextBox1.Text

        If temp > 1000 Then
            Label2.Text = "Warning - Temp is too high"
        Else
            Label2.Text = "Temp is OK"
        End If
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click

    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        Dim localVar As Integer
        localVar = localVar + 1
        example = example + 1
        MsgBox("LocalCar: " & localVar)
        MsgBox("GlobalVar: " & example)

    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        'make some numbers at random
        '**************************

        '1. Make the random number genrator
        Dim r As New Random

        '2. Create two random numbers
        Dim num1, num2 As Integer
        num1 = r.Next(0, 11) '0 - 10
        num2 = r.Next(1, 100) '1 - 99
        'Note: 1 higher on 2nd number

        MsgBox(num1 & " " & num2)
    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'When form initalizes...
        example = 100
    End Sub
End Class
