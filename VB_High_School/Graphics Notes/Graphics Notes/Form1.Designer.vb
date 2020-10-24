<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()> _
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form overrides dispose to clean up the component list.
    <System.Diagnostics.DebuggerNonUserCode()> _
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Required by the Windows Form Designer
    Private components As System.ComponentModel.IContainer

    'NOTE: The following procedure is required by the Windows Form Designer
    'It can be modified using the Windows Form Designer.  
    'Do not modify it using the code editor.
    <System.Diagnostics.DebuggerStepThrough()> _
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Dim resources As System.ComponentModel.ComponentResourceManager = New System.ComponentModel.ComponentResourceManager(GetType(Form1))
        Me.Label1 = New System.Windows.Forms.Label()
        Me.Button1 = New System.Windows.Forms.Button()
        Me.Button2 = New System.Windows.Forms.Button()
        Me.Button3 = New System.Windows.Forms.Button()
        Me.Button4 = New System.Windows.Forms.Button()
        Me.Timer1 = New System.Windows.Forms.Timer(Me.components)
        Me.Button5 = New System.Windows.Forms.Button()
        Me.Button6 = New System.Windows.Forms.Button()
        Me.PictureBox1 = New System.Windows.Forms.PictureBox()
        Me.WMP1 = New AxWMPLib.AxWindowsMediaPlayer()
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).BeginInit()
        CType(Me.WMP1, System.ComponentModel.ISupportInitialize).BeginInit()
        Me.SuspendLayout()
        '
        'Label1
        '
        Me.Label1.AutoSize = True
        Me.Label1.Location = New System.Drawing.Point(22, 30)
        Me.Label1.Name = "Label1"
        Me.Label1.Size = New System.Drawing.Size(39, 13)
        Me.Label1.TabIndex = 0
        Me.Label1.Text = "Label1"
        '
        'Button1
        '
        Me.Button1.Location = New System.Drawing.Point(12, 163)
        Me.Button1.Name = "Button1"
        Me.Button1.RightToLeft = System.Windows.Forms.RightToLeft.Yes
        Me.Button1.Size = New System.Drawing.Size(114, 23)
        Me.Button1.TabIndex = 1
        Me.Button1.Text = "Make Shapes"
        Me.Button1.UseVisualStyleBackColor = True
        '
        'Button2
        '
        Me.Button2.Location = New System.Drawing.Point(12, 192)
        Me.Button2.Name = "Button2"
        Me.Button2.Size = New System.Drawing.Size(114, 23)
        Me.Button2.TabIndex = 2
        Me.Button2.Text = "Clear Shapes"
        Me.Button2.UseVisualStyleBackColor = True
        '
        'Button3
        '
        Me.Button3.Location = New System.Drawing.Point(132, 163)
        Me.Button3.Name = "Button3"
        Me.Button3.Size = New System.Drawing.Size(117, 23)
        Me.Button3.TabIndex = 3
        Me.Button3.Text = "Activate Timer"
        Me.Button3.UseVisualStyleBackColor = True
        '
        'Button4
        '
        Me.Button4.Location = New System.Drawing.Point(132, 192)
        Me.Button4.Name = "Button4"
        Me.Button4.Size = New System.Drawing.Size(117, 23)
        Me.Button4.TabIndex = 4
        Me.Button4.Text = "Deactivate Timer"
        Me.Button4.UseVisualStyleBackColor = True
        '
        'Timer1
        '
        '
        'Button5
        '
        Me.Button5.Location = New System.Drawing.Point(255, 163)
        Me.Button5.Name = "Button5"
        Me.Button5.Size = New System.Drawing.Size(117, 23)
        Me.Button5.TabIndex = 5
        Me.Button5.Text = "Load Picture"
        Me.Button5.UseVisualStyleBackColor = True
        '
        'Button6
        '
        Me.Button6.Location = New System.Drawing.Point(255, 192)
        Me.Button6.Name = "Button6"
        Me.Button6.Size = New System.Drawing.Size(117, 23)
        Me.Button6.TabIndex = 6
        Me.Button6.Text = "Move Pic Down"
        Me.Button6.UseVisualStyleBackColor = True
        '
        'PictureBox1
        '
        Me.PictureBox1.BackColor = System.Drawing.SystemColors.ControlDark
        Me.PictureBox1.Location = New System.Drawing.Point(255, 30)
        Me.PictureBox1.Name = "PictureBox1"
        Me.PictureBox1.Size = New System.Drawing.Size(100, 93)
        Me.PictureBox1.SizeMode = System.Windows.Forms.PictureBoxSizeMode.StretchImage
        Me.PictureBox1.TabIndex = 7
        Me.PictureBox1.TabStop = False
        '
        'WMP1
        '
        Me.WMP1.Enabled = True
        Me.WMP1.Location = New System.Drawing.Point(378, 30)
        Me.WMP1.Name = "WMP1"
        Me.WMP1.OcxState = CType(resources.GetObject("WMP1.OcxState"), System.Windows.Forms.AxHost.State)
        Me.WMP1.Size = New System.Drawing.Size(203, 185)
        Me.WMP1.TabIndex = 8
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(6.0!, 13.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.ClientSize = New System.Drawing.Size(593, 247)
        Me.Controls.Add(Me.WMP1)
        Me.Controls.Add(Me.PictureBox1)
        Me.Controls.Add(Me.Button6)
        Me.Controls.Add(Me.Button5)
        Me.Controls.Add(Me.Button4)
        Me.Controls.Add(Me.Button3)
        Me.Controls.Add(Me.Button2)
        Me.Controls.Add(Me.Button1)
        Me.Controls.Add(Me.Label1)
        Me.Name = "Form1"
        Me.Text = "Graphic Notes"
        CType(Me.PictureBox1, System.ComponentModel.ISupportInitialize).EndInit()
        CType(Me.WMP1, System.ComponentModel.ISupportInitialize).EndInit()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub
    Friend WithEvents Label1 As System.Windows.Forms.Label
    Friend WithEvents Button1 As System.Windows.Forms.Button
    Friend WithEvents Button2 As System.Windows.Forms.Button
    Friend WithEvents Button3 As System.Windows.Forms.Button
    Friend WithEvents Button4 As System.Windows.Forms.Button
    Friend WithEvents Timer1 As System.Windows.Forms.Timer
    Friend WithEvents Button5 As System.Windows.Forms.Button
    Friend WithEvents Button6 As System.Windows.Forms.Button
    Friend WithEvents PictureBox1 As System.Windows.Forms.PictureBox
    Friend WithEvents WMP1 As AxWMPLib.AxWindowsMediaPlayer

End Class
