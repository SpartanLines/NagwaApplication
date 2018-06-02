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
    public partial class Ask_question : Form
    {
        Controller controllerObj;
        int QID = 1;
        public Ask_question()
        {
            controllerObj = new Controller();
            InitializeComponent();
            speciality.Items.Add("Cardiology");
            speciality.Items.Add("Dermatology‎");
            speciality.Items.Add("Diabetology");
            speciality.Items.Add("Psychiatry");
            speciality.Items.Add("Immunology");
            speciality.Items.Add("Pathology");
            speciality.Items.Add("Pediatricians‎");
            speciality.Items.Add(" Neurology‎ ‎");
            speciality.Items.Add(" Surgery");
            speciality.Items.Add(" Hematology");
            speciality.Items.Add("  Gastroenterology");
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void Ask_question_Load(object sender, EventArgs e)
        {

        }

        private void submit_Click(object sender, EventArgs e)
        {
            if (speciality.Text == "" || textBox1.Text == "")//validation part
            {
                MessageBox.Show("Please, insert all values");
            }
            else
            {
                patientlogin p = new patientlogin();
                int pid = p.getPID();
                var date = DateTime.Now;
                var day = DateTime.Today;
                string a = "ddsf";
                
                int r = controllerObj.Addquestion(QID, pid, speciality.Text.ToString(), day, Convert.ToInt16(date.ToString("hh")), Convert.ToInt16(date.ToString("mm")), textBox1.Text.ToString());
                if (r > 0)
                {   MessageBox.Show("question added successfully");
                Patient_Functionalities menu = new Patient_Functionalities();
                menu.Show();
                }
                else
                    MessageBox.Show("Insertion Failed");
            }
        }
    }
}
