using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyProject
{

    public partial class Form1 : Form
    {
        Controller ControllerObj;
        int id;
        public Form1(int coming)//int num)
        {
            InitializeComponent();
            id = coming;

        }

        // public int id=9;
        public const int WM_NCLBUTTONDOWN = 0xA1;
        public const int HT_CAPTION = 0x2;
        
        [System.Runtime.InteropServices.DllImportAttribute("user32.dll")]
        public static extern int SendMessage(IntPtr hWnd, int Msg, int wParam, int lParam);
        [System.Runtime.InteropServices.DllImportAttribute("user32.dll")]
        public static extern bool ReleaseCapture();
        private void Form1_Load(object sender, EventArgs e)
        {
            dashboard1.BringToFront();
            ControllerObj = new Controller();
            DataTable dt = ControllerObj.GetName(id);
            label1.Text = dt.Rows[0][0].ToString();        
        }

       private void Form1_MouseDown(object sender, System.Windows.Forms.MouseEventArgs e)
{     
    if (e.Button == MouseButtons.Left)
    {
        
        ReleaseCapture();
        SendMessage(Handle, WM_NCLBUTTONDOWN, HT_CAPTION, 0);
    }
}

       private void panel7_MouseDown(object sender, MouseEventArgs e)
       {
           if (e.Button == MouseButtons.Left)
           {
               ReleaseCapture();
               SendMessage(Handle, WM_NCLBUTTONDOWN, HT_CAPTION, 0);
           }
       }

       private void label1_Click(object sender, EventArgs e)
       {
           
       }

       private void button1_Click(object sender, EventArgs e)
       {
           panel5.Top = button1.Top;
           panel5.BringToFront();
           dashboard1.BringToFront();
       
       }

       private void button5_Click(object sender, EventArgs e)
       {
           panel5.Top = button5.Top;
            createCase1.BringToFront();
           panel5.BringToFront();
       }

       private void button6_Click(object sender, EventArgs e)
       {
           panel5.Top = button6.Top;
           casesList1.BringToFront();
           casesList1.Update();
           panel5.BringToFront();
       }

       private void button4_Click(object sender, EventArgs e)
       {
           panel5.Top = button4.Top;
           panel5.BringToFront();
           Question q = new Question();
           q.Show();
       }

       private void button3_Click(object sender, EventArgs e)
       {
           panel5.Top = button3.Top;
           panel5.BringToFront();
           questionslist1.BringToFront();
          
          
          
           

       }

      private void panel2_Paint(object sender, PaintEventArgs e)
       {

       }

      private void userControl11_Load(object sender, EventArgs e)
      {

      }

      private void pictureBox1_Click(object sender, EventArgs e)
      {

      }

      private void panel1_Paint(object sender, PaintEventArgs e)
      {

      }



       

       
    }
}
