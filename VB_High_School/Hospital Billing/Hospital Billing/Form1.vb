Public Class Form1
    Dim Average_bill As Double
    Dim Lowest_Bill As Double
    Dim Highest_Bill As Double
    Dim BillTotal As Double
    Dim DoublePats, PrivatePats, IntensePats As Integer


    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Open file (based on wante directory)
        If CheckBox1.Checked = True Then
            'Just to make your life easier Mr Fox
            FileOpen(1, "U:\hospital.txt", OpenMode.Input)
        Else
            FileOpen(1, "U:\Programing_Info\hospital.txt", OpenMode.Input)
        End If


        'Set up values for the file
        Dim PatientName, Acomidations, Service As String
        Dim DaysStayed As Integer
        Dim Bill As Double


        ListView1.View = View.Details

        'Loop that stuff up
        Do While Not EOF(1)
            'Establish Inputs
            Input(1, PatientName)
            Input(1, DaysStayed)
            Input(1, Acomidations)
            Input(1, Service)

            'Calculate and check errors
            If Acomidations = "I" Then
                If Service = "N" Then
                    Bill = (1398 + 300) * DaysStayed
                Else
                    Bill = 1398 * DaysStayed
                End If
                IntensePats = IntensePats + 1
            ElseIf Acomidations = "D" Then
                If Service = "T" Then
                    Bill = (935 + 35) * DaysStayed
                Else
                    Bill = 935 * DaysStayed
                End If
                DoublePats = DoublePats + 1
            ElseIf Acomidations = "P" Then
                Bill = 1260 * DaysStayed
                PrivatePats = PrivatePats + 1
            Else
                'ERROR message
                MsgBox("Patient " & PatientName & " dose not have acomidation information!")
            End If

            'This will come into play latter
            Average_bill = Average_bill + Bill

            If Highest_Bill < Bill Then
                Highest_Bill = Bill
            End If

            'If low bill is 0 then set it as current otherwise compair it
            If Lowest_Bill = 0 Then
                Lowest_Bill = Bill
            ElseIf Lowest_Bill > Bill Then
                Lowest_Bill = Bill
            End If

                'Add values to rows
                Dim row As New ListViewItem(PatientName)
                row.SubItems.Add(DaysStayed)
                row.SubItems.Add(Acomidations)
                row.SubItems.Add(Service)
                row.SubItems.Add(Format(Bill, "currency"))

                'Show Information
                ListView1.Items.Add(row)

                'Count bills
                BillTotal = BillTotal + Bill

        Loop
        'Close file
        FileClose(1)

        'Calculate Average
        Average_bill = Average_bill / (DoublePats + PrivatePats + IntensePats)

        'Show stats!
        Label1.Text = DoublePats
        Label2.Text = PrivatePats
        Label3.Text = IntensePats
        Label4.Text = Format(BillTotal, "currency")
        'Extra credit :D
        MsgBox("Average Bill: " & Format(Average_bill, "currency") & " Highest Bill: " & Format(Highest_Bill, "currency") & " Lowest Bill: " & Format(Lowest_Bill, "currency"))


    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        Me.Close()
    End Sub
End Class
