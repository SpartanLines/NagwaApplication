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
    public partial class Form3 : Form
    {
        int ID1;
        int ID2;
        int ID3;
        Controller ControllerObj;
        public Form3()
        {
            InitializeComponent();
            ControllerObj = new Controller();
        }

        private void GetDocsB_Click(object sender, EventArgs e)
        {
            ControllerObj = new Controller();
            DataTable DT = ControllerObj.GetDoctors();
            DocsDG.DataSource = DT;
            DocsDG.Refresh();
        }

        private void PatientsDG_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {

        }

        private void GetPatientsB_Click(object sender, EventArgs e)
        {
            ControllerObj = new Controller();
            DataTable DT = ControllerObj.GetPatients();
            PatientsDG.DataSource = DT;
            PatientsDG.Refresh();
        }

        private void GetDonorsB_Click(object sender, EventArgs e)
        {
            ControllerObj = new Controller();
            DataTable DT = ControllerObj.GetDonors();
            DonorsDG.DataSource = DT;
            DonorsDG.Refresh();
        }

        private void DelDonB_Click(object sender, EventArgs e)
        {
            int c = ControllerObj.DeleteDonUser(ID3);
            if (c== 0)
            {
                MessageBox.Show("failed");
            }
            else
            {
                MessageBox.Show("successfully!");
                DataTable DT = ControllerObj.GetDonors();
                DonorsDG.DataSource = DT;
                DonorsDG.Refresh();

            }

        }

        private void DocsDG_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
           


        }

        private void DelDocB_Click(object sender, EventArgs e)
        {
            int c = ControllerObj.DeleteDocUser(ID1);
            if (c == 0)
            {
                MessageBox.Show("failed");
            }
            else
            {
                MessageBox.Show("successfully!");
                DataTable DT = ControllerObj.GetDoctors();
                DocsDG.DataSource = DT;
                DocsDG.Refresh();
            }
            
      

        }

        private void DelPatB_Click(object sender, EventArgs e)
        {
            int c = ControllerObj.DeletePUser(ID2);
            if (c == 0)
            {
                MessageBox.Show("failed");
            }
            else
            {
                MessageBox.Show("successfully!");
                DataTable DT = ControllerObj.GetPatients();
                PatientsDG.DataSource = DT;
                PatientsDG.Refresh();
            } 


        }

        private void DonorsDG_CellContentClick(object sender, DataGridViewCellEventArgs e)
        {
           

        }

        private void PatientsDG_SelectionChanged(object sender, EventArgs e)
        {

            ControllerObj = new Controller();
            string id = PatientsDG.Rows[PatientsDG.CurrentCell.RowIndex].Cells[2].Value.ToString();
            ID2 = Convert.ToInt32(id);
        }

        private void DonorsDG_SelectionChanged(object sender, EventArgs e)
        {
            ControllerObj = new Controller();
            string id = DonorsDG.Rows[DonorsDG.CurrentCell.RowIndex].Cells[2].Value.ToString();
            ID3 = Convert.ToInt32(id);

        }

        private void DocsDG_SelectionChanged(object sender, EventArgs e)
        {
            ControllerObj = new Controller();
            string id = DocsDG.Rows[DocsDG.CurrentCell.RowIndex].Cells[2].Value.ToString();
            ID1 = Convert.ToInt32(id);
        }

        private void Form3_Load(object sender, EventArgs e)
        {

        }
    }
}
