Public Class Form1
    'step1: Graphics var
    '******************************************
    Dim g As Graphics
    '******************************************
    'Look for U:\Visual Studio 2010\Projects\Graphics Notes\Graphics Notes\bin\Debug
    'For how to store files in the project
    Dim count As Integer
    Dim x, y As Integer
    Dim a, b As Integer

    Private Sub Form1_Click(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Click
        'CLICK
        Dim mypoint As Point
        mypoint = New Point(MousePosition.X - Me.Location.X - 4 - 12, MousePosition.Y - Me.Location.Y - 30 - 12)
        Dim b As New SolidBrush(Color.Azure)
        g.FillEllipse(Brushes.Red, mypoint.X, mypoint.Y, 25, 25)

    End Sub

    Private Sub Form1_Load(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles MyBase.Load
        'Step 2: create a graphics var and set to current form
        '***************************************************************
        g = Me.CreateGraphics
        '***************************************************************

        'Initialize PicY
        'picy = picturebox1.location.y

        'stop wmp1 b/x it plays automatically
        WMP1.Ctlcontrols.stop()
    End Sub

    Private Sub Button1_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button1.Click
        'Step 3: Draw stuff
        '******************************************

        'draw rectangle (color, x, y, width, height)
        g.DrawRectangle(Pens.Blue, 10, 10, 150, 25)

        'draw circle - draws an ellipse within rectangular dimensions
        g.DrawEllipse(Pens.Crimson, 100, 50, 50, 50)

        'Draw line ((x1, v1) x2, y2))
        g.DrawLine(Pens.DarkOrange, 0, 100, 100, 200)

        'Draw filled rectangle
        g.FillRectangle(Brushes.GreenYellow, 0, 0, 50, 150)

        'Custom Pen
        Dim mypen As New Pen(Color.BlueViolet, 10) '10 = width
        g.DrawLine(mypen, 0, 0, 200, 200)
        'Change the event to drag to make it paint a constant circle behind
    End Sub

    Private Sub Timer1_Tick(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Timer1.Tick
        'What to do when timer ticks
        count = count + 1
        Label1.Text = count

        'Move a rectangle
        g.Clear(Me.BackColor)
        g.DrawRectangle(Pens.Blue, count, 50, 100, 100)
    End Sub

    Private Sub Button3_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button3.Click
        'Activate timer
        Timer1.Enabled = True
        WMP1.Ctlcontrols.play()

    End Sub

    Private Sub Button4_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button4.Click
        'deactivate timer
        Timer1.Enabled = False
        WMP1.Ctlcontrols.stop()
    End Sub

    Private Sub Button6_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button6.Click
        'Move button down
        PictureBox1.Location = New Point(PictureBox1.Location.X, PictureBox1.Location.Y + 10)
    End Sub

    Private Sub Button2_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button2.Click
        'clear drawings - must give background color
        g.Clear(Me.BackColor)
    End Sub

    Private Sub Button5_Click(ByVal sender As System.Object, ByVal e As System.EventArgs) Handles Button5.Click
        'Load picture
        PictureBox1.Image = New Bitmap("AWESOME FACE.png")

    End Sub

End Class
