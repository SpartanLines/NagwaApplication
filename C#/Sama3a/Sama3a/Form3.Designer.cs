namespace MyProject
{
    partial class Form3
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.GetDocsB = new System.Windows.Forms.Button();
            this.GetPatientsB = new System.Windows.Forms.Button();
            this.GetDonorsB = new System.Windows.Forms.Button();
            this.DocsDG = new System.Windows.Forms.DataGridView();
            this.PatientsDG = new System.Windows.Forms.DataGridView();
            this.DonorsDG = new System.Windows.Forms.DataGridView();
            this.DelDocB = new System.Windows.Forms.Button();
            this.DelPatB = new System.Windows.Forms.Button();
            this.DelDonB = new System.Windows.Forms.Button();
            ((System.ComponentModel.ISupportInitialize)(this.DocsDG)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.PatientsDG)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.DonorsDG)).BeginInit();
            this.SuspendLayout();
            // 
            // GetDocsB
            // 
            this.GetDocsB.Location = new System.Drawing.Point(155, 115);
            this.GetDocsB.Name = "GetDocsB";
            this.GetDocsB.Size = new System.Drawing.Size(215, 23);
            this.GetDocsB.TabIndex = 0;
            this.GetDocsB.Text = "Retrieve Doctors";
            this.GetDocsB.UseVisualStyleBackColor = true;
            this.GetDocsB.Click += new System.EventHandler(this.GetDocsB_Click);
            // 
            // GetPatientsB
            // 
            this.GetPatientsB.Location = new System.Drawing.Point(548, 115);
            this.GetPatientsB.Name = "GetPatientsB";
            this.GetPatientsB.Size = new System.Drawing.Size(224, 23);
            this.GetPatientsB.TabIndex = 1;
            this.GetPatientsB.Text = "Retrieve Patients";
            this.GetPatientsB.UseVisualStyleBackColor = true;
            this.GetPatientsB.Click += new System.EventHandler(this.GetPatientsB_Click);
            // 
            // GetDonorsB
            // 
            this.GetDonorsB.Location = new System.Drawing.Point(1109, 115);
            this.GetDonorsB.Name = "GetDonorsB";
            this.GetDonorsB.Size = new System.Drawing.Size(220, 23);
            this.GetDonorsB.TabIndex = 2;
            this.GetDonorsB.Text = "Retrieve Donors";
            this.GetDonorsB.UseVisualStyleBackColor = true;
            this.GetDonorsB.Click += new System.EventHandler(this.GetDonorsB_Click);
            // 
            // DocsDG
            // 
            this.DocsDG.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DocsDG.Location = new System.Drawing.Point(35, 175);
            this.DocsDG.Name = "DocsDG";
            this.DocsDG.RowTemplate.Height = 24;
            this.DocsDG.Size = new System.Drawing.Size(394, 284);
            this.DocsDG.TabIndex = 3;
            this.DocsDG.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.DocsDG_CellContentClick);
            this.DocsDG.SelectionChanged += new System.EventHandler(this.DocsDG_SelectionChanged);
            // 
            // PatientsDG
            // 
            this.PatientsDG.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.PatientsDG.Location = new System.Drawing.Point(475, 175);
            this.PatientsDG.Name = "PatientsDG";
            this.PatientsDG.RowTemplate.Height = 24;
            this.PatientsDG.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.PatientsDG.Size = new System.Drawing.Size(405, 284);
            this.PatientsDG.TabIndex = 4;
            this.PatientsDG.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.PatientsDG_CellContentClick);
            this.PatientsDG.SelectionChanged += new System.EventHandler(this.PatientsDG_SelectionChanged);
            // 
            // DonorsDG
            // 
            this.DonorsDG.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.DonorsDG.Location = new System.Drawing.Point(908, 175);
            this.DonorsDG.Name = "DonorsDG";
            this.DonorsDG.RowTemplate.Height = 24;
            this.DonorsDG.Size = new System.Drawing.Size(465, 284);
            this.DonorsDG.TabIndex = 5;
            this.DonorsDG.CellContentClick += new System.Windows.Forms.DataGridViewCellEventHandler(this.DonorsDG_CellContentClick);
            this.DonorsDG.SelectionChanged += new System.EventHandler(this.DonorsDG_SelectionChanged);
            // 
            // DelDocB
            // 
            this.DelDocB.Location = new System.Drawing.Point(183, 56);
            this.DelDocB.Name = "DelDocB";
            this.DelDocB.Size = new System.Drawing.Size(166, 23);
            this.DelDocB.TabIndex = 6;
            this.DelDocB.Text = "Delete Doctor";
            this.DelDocB.UseVisualStyleBackColor = true;
            this.DelDocB.Click += new System.EventHandler(this.DelDocB_Click);
            // 
            // DelPatB
            // 
            this.DelPatB.Location = new System.Drawing.Point(591, 56);
            this.DelPatB.Name = "DelPatB";
            this.DelPatB.Size = new System.Drawing.Size(181, 23);
            this.DelPatB.TabIndex = 7;
            this.DelPatB.Text = "Delete Patient";
            this.DelPatB.UseVisualStyleBackColor = true;
            this.DelPatB.Click += new System.EventHandler(this.DelPatB_Click);
            // 
            // DelDonB
            // 
            this.DelDonB.Location = new System.Drawing.Point(1109, 56);
            this.DelDonB.Name = "DelDonB";
            this.DelDonB.Size = new System.Drawing.Size(150, 23);
            this.DelDonB.TabIndex = 8;
            this.DelDonB.Text = "DeleteDonor";
            this.DelDonB.UseVisualStyleBackColor = true;
            this.DelDonB.Click += new System.EventHandler(this.DelDonB_Click);
            // 
            // Form3
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1396, 516);
            this.Controls.Add(this.DelDonB);
            this.Controls.Add(this.DelPatB);
            this.Controls.Add(this.DelDocB);
            this.Controls.Add(this.DonorsDG);
            this.Controls.Add(this.PatientsDG);
            this.Controls.Add(this.DocsDG);
            this.Controls.Add(this.GetDonorsB);
            this.Controls.Add(this.GetPatientsB);
            this.Controls.Add(this.GetDocsB);
            this.Name = "Form3";
            this.Text = "F";
            this.Load += new System.EventHandler(this.Form3_Load);
            ((System.ComponentModel.ISupportInitialize)(this.DocsDG)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.PatientsDG)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.DonorsDG)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button GetDocsB;
        private System.Windows.Forms.Button GetPatientsB;
        private System.Windows.Forms.Button GetDonorsB;
        private System.Windows.Forms.DataGridView DocsDG;
        private System.Windows.Forms.DataGridView PatientsDG;
        private System.Windows.Forms.DataGridView DonorsDG;
        private System.Windows.Forms.Button DelDocB;
        private System.Windows.Forms.Button DelPatB;
        private System.Windows.Forms.Button DelDonB;
    }
}