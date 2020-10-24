Public Class Form1
    'GLOBAL VARS!!
    Dim decimal_count As Integer
    Dim ACC1_Named, ACC2_Named As Boolean
    Dim Input_String, ACC1_pass, ACC2_pass, ACC1_Name, ACC2_name As String
    Dim Accnt_Bal, Pre_Accnt_Bal, User_Input, ACC1_Ref, ACC2_Ref As Double

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Starting stuff
        Accnt_Bal = 1000
        'Acc1 will be checked initaly
        ACC1_Ref = 1000
        ACC2_Ref = 1000
        Label1.Text = Format(Accnt_Bal, "currency")

        ACC1_pass = "cake"
        ACC2_pass = "lol"
        ACC1_Named = False
        ACC2_Named = False
        RadioButton1.Checked = True

        ACC1_Name = InputBox("Type the name for Account #1")
        Label7.Text = ACC1_Name
        Label7.Font = New Font(Label7.Font.Name, Label7.Font.Size, FontStyle.Bold)
        Label3.Text = Format(ACC1_Ref, "currency")
        ACC2_name = InputBox("Type the name for Account #2")
        Label8.Text = ACC2_name
        Label4.Text = Format(ACC2_Ref, "currency")

        MsgBox("Hola! Welcome to the ATM. Current Balance: " & Accnt_Bal)
    End Sub

    Private Sub ChangeBalance(ByVal Amount_Delta As Double, ByVal Adding_Money As Boolean)
        'Set Vars
        If RadioButton1.Checked = True Then
            Accnt_Bal = ACC1_Ref
        ElseIf RadioButton2.Checked = True Then
            Accnt_Bal = ACC2_Ref
        Else
            MsgBox("Check and account to begin transaction!")
            Amount_Delta = 0
        End If
        Pre_Accnt_Bal = Accnt_Bal

        'Params
        If Amount_Delta = 0 Then
            'Return a msg
            MsgBox("0 is not valid... try agian")

        ElseIf Adding_Money = True Then
            Accnt_Bal = Accnt_Bal + Math.Abs(Amount_Delta)
            If RadioButton1.Checked = True Then
                ACC1_Ref = Accnt_Bal
                Label1.Text = Format(ACC1_Ref, "currency")
                Label3.Text = Format(ACC1_Ref, "currency")
            ElseIf RadioButton2.Checked = True Then
                ACC2_Ref = Accnt_Bal
                Label1.Text = Format(ACC2_Ref, "currency")
                Label4.Text = Format(ACC2_Ref, "currency")
            End If
        ElseIf Amount_Delta < Accnt_Bal And Adding_Money = False Then
            Accnt_Bal = Accnt_Bal - Amount_Delta
            If RadioButton1.Checked = True Then
                ACC1_Ref = Accnt_Bal
                Label1.Text = Format(ACC1_Ref, "currency")
                Label3.Text = Format(ACC1_Ref, "currency")
            ElseIf RadioButton2.Checked = True Then
                ACC2_Ref = Accnt_Bal
                Label1.Text = Format(ACC2_Ref, "currency")
                Label4.Text = Format(ACC2_Ref, "currency")
            End If
        Else
            MsgBox("Insufficent Funds! Current Balance: " & Accnt_Bal)
        End If

        Receipt()

        'Clear Values!
        decimal_count = 0
        Input_String = "0"
        TextBox1.Clear()
        User_Input = 0

    End Sub
    Private Sub Receipt()
        Dim want_1 As String
        'receipt for you?
        Want_1 = InputBox("Would you like a receipt? (Type Yes or No)")

        'EXCENTRIC FILTER :D !
        If Want_1 = "Yes" Or Want_1 = "yes" Or Want_1 = "Yea" Or Want_1 = "yea" Or Want_1 = "Sure" Or Want_1 = "sure" Then
            MsgBox("Transaction complete! Original Balance: " & Pre_Accnt_Bal & " . Current Accnt Balance: " & Accnt_Bal & ". Have a nice Day")
        ElseIf Want_1 = "No" Or Want_1 = "no" Or Want_1 = "Nah" Or Want_1 = "nah" Then
            MsgBox("Have a nice day!")
        Else
            Want_1 = InputBox("Sorry, I didnt get that; Would you like a receipt? (Type Yes or No)")
        End If
    End Sub
    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Deposit
        User_Input = Input_String

        If User_Input <> 0 Then
            ChangeBalance(User_Input, True)
            'MMmm redisplay account ammount?
        End If

    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'Withdraw
        User_Input = Input_String
        If User_Input <> 0 Then
            ChangeBalance(User_Input, False)
        End If

    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        'Query the balance
        If RadioButton1.Checked = True Then
            MsgBox("Current Account Balance: " & Format(ACC1_Ref, "currency"))
            Label3.Text = Format(ACC1_Ref, "currency")
        ElseIf RadioButton2.Checked = True Then
            MsgBox("Current Account Balance: " & Format(ACC2_Ref, "currency"))
            Label4.Text = Format(ACC2_Ref, "currency")
        Else
            MsgBox("Select an account first...")
        End If


    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        'Give $20
        ChangeBalance(20, False)

    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        'Give $60
        ChangeBalance(60, False)
    End Sub

    Private Sub Button2String(ByVal Number_Add As String)
        'Check out that input son
        Input_String = Input_String & Number_Add
        TextBox1.Text = Input_String
    End Sub
    'Start Numberpad!
    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        'God these buttons are going to get annoying
        Button2String(1)
    End Sub

    Private Sub Button9_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button9.Click
        Button2String(2)
    End Sub

    Private Sub Button7_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button7.Click
        Button2String(3)
    End Sub

    Private Sub Button8_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button8.Click
        Button2String(4)
    End Sub

    Private Sub Button10_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button10.Click
        Button2String(5)
    End Sub

    Private Sub Button11_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button11.Click
        Button2String(6)
    End Sub

    Private Sub Button12_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button12.Click
        Button2String(7)
    End Sub

    Private Sub Button13_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button13.Click
        Button2String(8)
    End Sub

    Private Sub Button14_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button14.Click
        Button2String(9)
    End Sub

    Private Sub Button16_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button16.Click
        Button2String(0)
    End Sub

    Private Sub Button17_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button17.Click
        'Decimal Point!
        If decimal_count <> 1 Then
            Button2String(".")
            decimal_count = 1
        End If

    End Sub

    Private Sub Button15_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button15.Click
        'Clear text and related
        TextBox1.Clear()
        decimal_count = 0
        Input_String = "0"

        If RadioButton1.Checked = True Then
            Accnt_Bal = ACC1_Ref
            Label1.Text = Format(ACC1_Ref, "currency")
        ElseIf RadioButton2.Checked = True Then
            Accnt_Bal = ACC2_Ref
            Label1.Text = Format(ACC2_Ref, "currency")
        End If

        Label3.Text = Format(ACC1_Ref, "currency")
        Label4.Text = Format(ACC2_Ref, "currency")
    End Sub

    Private Sub Button18_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button18.Click
        Me.Close()

    End Sub
    Private Sub RadioButton1_TextChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles RadioButton1.TextChanged
        'On account name change of #1
        If ACC1_Named = False Then
            ACC1_Named = True
        Else
            MsgBox("Account 1 is already named!!")
        End If
    End Sub

    Private Sub RadioButton2_TextChanged(ByVal sender As Object, ByVal e As System.EventArgs) Handles RadioButton2.TextChanged
        'On account name change of #2
        If ACC2_Named = False Then
            ACC2_Named = True
        Else
            MsgBox("Account 2 is already named!!")
        End If

    End Sub
    'FINISH ON TUESDAY!
    Private Sub Button19_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button19.Click
        Dim user_input As String

        'Change account
        If RadioButton1.Checked = True Then
            user_input = InputBox("Enter password for Account 2")
            If user_input = ACC2_pass Then
                RadioButton2.Checked = True
                Label7.Font = New Font(Label7.Font.Name, Label7.Font.Size, FontStyle.Regular)
                Label8.Font = New Font(Label7.Font.Name, Label8.Font.Size, FontStyle.Bold)
            Else
                MsgBox("Password was incorrect, Try again")
            End If

        ElseIf RadioButton2.Checked = True Then
            user_input = InputBox("Enter password for Account 1")
            If user_input = ACC1_pass Then
                RadioButton1.Checked = True
                Label7.Font = New Font(Label7.Font.Name, Label7.Font.Size, FontStyle.Bold)
                Label8.Font = New Font(Label8.Font.Name, Label8.Font.Size, FontStyle.Regular)
            Else
                MsgBox("Password was incorrect, Try again")
            End If
        End If
        'Something else...

    End Sub
End Class
