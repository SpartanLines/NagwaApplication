using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyProject
{
    public partial class Questionslist : UserControl
    {
        Controller ControllerObj;
        public Questionslist()
        {
            InitializeComponent();
            comboBox2.Hide();
            comboBox1.SelectedIndex = 1;
            dataGridView1.BorderStyle = BorderStyle.None;
            dataGridView1.AlternatingRowsDefaultCellStyle.BackColor = Color.FromArgb(238, 239, 249);
            dataGridView1.CellBorderStyle = DataGridViewCellBorderStyle.SingleHorizontal;
            dataGridView1.DefaultCellStyle.SelectionBackColor = Color.DarkTurquoise;
            dataGridView1.DefaultCellStyle.SelectionForeColor = Color.WhiteSmoke;
            dataGridView1.BackgroundColor = Color.White;

            dataGridView1.EnableHeadersVisualStyles = false;
            dataGridView1.ColumnHeadersBorderStyle = DataGridViewHeaderBorderStyle.None;
            dataGridView1.ColumnHeadersDefaultCellStyle.BackColor = Color.FromArgb(20, 25, 72);
            dataGridView1.ColumnHeadersDefaultCellStyle.ForeColor = Color.White;
            
        
        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            string currentselected= comboBox1.Text;
            if (currentselected== "Speciality")
            {
                comboBox2.Show();
                textBox1.Hide();
            }
            else  if(currentselected=="Keyword")
            {
                textBox1.Show();
                comboBox2.Hide();
            }
            else
            {
                comboBox2.Hide();
                textBox1.Hide();
            }
        }

        private void dataGridView1_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
            string id = dataGridView1.Rows[dataGridView1.CurrentCell.RowIndex].Cells[0].Value.ToString();
            int ID = Convert.ToInt32(id);
            UserControl1 newindow = new UserControl1(ID);
            // newindow.Top = this.Top;
            this.Parent.Controls.Add(newindow);
            newindow.Location = new Point(182,103);
         
            newindow.Show();
            newindow.BringToFront();
          //  this.Controls.Add(newindow);
            
            
            
        }

        private void comboBox2_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            string method = comboBox1.Text;
            string second = "";
            if(method=="Speciality")
            {
                second = comboBox2.Text;
            }
            else
            {
                second = textBox1.Text;
            }
            ControllerObj = new Controller();
            DataTable dt = ControllerObj.QuestionList(method,second);
            dataGridView1.DataSource = dt;
            // dataGridView1.Columns[3].Width = 350;
            
          
            
        
        }

      
        
      
    }
}
