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
    public partial class Patient_Functionalities : Form
    {
        public Patient_Functionalities()
        {
            InitializeComponent();
        }

        private void askquestion_Click(object sender, EventArgs e)
        {
            Ask_question a = new Ask_question();
            a.Show();
        }

        private void searchquestion_Click(object sender, EventArgs e)
        {
            Search_question a = new Search_question();
            a.Show();
        }
         
        private void update_Click(object sender, EventArgs e)
        {
            Update a = new Update();
            a.Show();
        }

        private void searchhosp_Click(object sender, EventArgs e)
        {
            Search_hospital h = new Search_hospital();
            h.Show();
        }

        private void searchmed_Click(object sender, EventArgs e)
        {
            Search_medicine m = new Search_medicine();
            m.Show();
        }

        private void askdonation_Click(object sender, EventArgs e)
        {

        }

        private void reserve_Click(object sender, EventArgs e)
        {
            reservation r = new reservation();
            r.Show();

        }
    }
}
