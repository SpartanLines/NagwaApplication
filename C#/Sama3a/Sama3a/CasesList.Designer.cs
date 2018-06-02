namespace MyProject
{
    partial class CasesList
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

        #region Component Designer generated code

        /// <summary> 
        /// Required method for Designer support - do not modify 
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            DevExpress.XtraGrid.GridFormatRule gridFormatRule1 = new DevExpress.XtraGrid.GridFormatRule();
            this.gridControl1 = new DevExpress.XtraGrid.GridControl();
            this.cardView1 = new DevExpress.XtraGrid.Views.Card.CardView();
            ((System.ComponentModel.ISupportInitialize)(this.gridControl1)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.cardView1)).BeginInit();
            this.SuspendLayout();
            // 
            // gridControl1
            // 
            this.gridControl1.Dock = System.Windows.Forms.DockStyle.Fill;
            this.gridControl1.Location = new System.Drawing.Point(0, 0);
            this.gridControl1.MainView = this.cardView1;
            this.gridControl1.Name = "gridControl1";
            this.gridControl1.Size = new System.Drawing.Size(797, 437);
            this.gridControl1.TabIndex = 0;
            this.gridControl1.ViewCollection.AddRange(new DevExpress.XtraGrid.Views.Base.BaseView[] {
            this.cardView1});
            // 
            // cardView1
            // 
            this.cardView1.Appearance.CardCaption.BackColor = System.Drawing.Color.DarkTurquoise;
            this.cardView1.Appearance.CardCaption.BorderColor = System.Drawing.Color.DarkTurquoise;
            this.cardView1.Appearance.CardCaption.Font = new System.Drawing.Font("Tahoma", 8F, System.Drawing.FontStyle.Bold);
            this.cardView1.Appearance.CardCaption.ForeColor = System.Drawing.Color.Black;
            this.cardView1.Appearance.CardCaption.Options.UseBackColor = true;
            this.cardView1.Appearance.CardCaption.Options.UseBorderColor = true;
            this.cardView1.Appearance.CardCaption.Options.UseFont = true;
            this.cardView1.Appearance.CardCaption.Options.UseForeColor = true;
            this.cardView1.Appearance.EmptySpace.BackColor = System.Drawing.Color.Azure;
            this.cardView1.Appearance.EmptySpace.Options.UseBackColor = true;
            this.cardView1.Appearance.FieldCaption.BackColor = System.Drawing.Color.GhostWhite;
            this.cardView1.Appearance.FieldCaption.BackColor2 = System.Drawing.Color.GhostWhite;
            this.cardView1.Appearance.FieldCaption.ForeColor = System.Drawing.Color.Black;
            this.cardView1.Appearance.FieldCaption.Options.UseBackColor = true;
            this.cardView1.Appearance.FieldCaption.Options.UseForeColor = true;
            this.cardView1.Appearance.FieldValue.BackColor = System.Drawing.Color.White;
            this.cardView1.Appearance.FieldValue.ForeColor = System.Drawing.Color.Black;
            this.cardView1.Appearance.FieldValue.Options.UseBackColor = true;
            this.cardView1.Appearance.FieldValue.Options.UseForeColor = true;
            this.cardView1.Appearance.FilterCloseButton.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(212)))), ((int)(((byte)(208)))), ((int)(((byte)(200)))));
            this.cardView1.Appearance.FilterCloseButton.BackColor2 = System.Drawing.Color.FromArgb(((int)(((byte)(165)))), ((int)(((byte)(90)))), ((int)(((byte)(220)))));
            this.cardView1.Appearance.FilterCloseButton.BorderColor = System.Drawing.Color.FromArgb(((int)(((byte)(212)))), ((int)(((byte)(208)))), ((int)(((byte)(200)))));
            this.cardView1.Appearance.FilterCloseButton.ForeColor = System.Drawing.Color.Black;
            this.cardView1.Appearance.FilterCloseButton.GradientMode = System.Drawing.Drawing2D.LinearGradientMode.ForwardDiagonal;
            this.cardView1.Appearance.FilterCloseButton.Options.UseBackColor = true;
            this.cardView1.Appearance.FilterCloseButton.Options.UseBorderColor = true;
            this.cardView1.Appearance.FilterCloseButton.Options.UseForeColor = true;
            this.cardView1.Appearance.FilterPanel.BackColor = System.Drawing.Color.Indigo;
            this.cardView1.Appearance.FilterPanel.BackColor2 = System.Drawing.Color.FromArgb(((int)(((byte)(212)))), ((int)(((byte)(208)))), ((int)(((byte)(200)))));
            this.cardView1.Appearance.FilterPanel.ForeColor = System.Drawing.Color.Cornsilk;
            this.cardView1.Appearance.FilterPanel.GradientMode = System.Drawing.Drawing2D.LinearGradientMode.ForwardDiagonal;
            this.cardView1.Appearance.FilterPanel.Options.UseBackColor = true;
            this.cardView1.Appearance.FilterPanel.Options.UseForeColor = true;
            this.cardView1.Appearance.FocusedCardCaption.BackColor = System.Drawing.Color.Red;
            this.cardView1.Appearance.FocusedCardCaption.BackColor2 = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(100)))), ((int)(((byte)(100)))));
            this.cardView1.Appearance.FocusedCardCaption.BorderColor = System.Drawing.Color.Red;
            this.cardView1.Appearance.FocusedCardCaption.ForeColor = System.Drawing.Color.White;
            this.cardView1.Appearance.FocusedCardCaption.Options.UseBackColor = true;
            this.cardView1.Appearance.FocusedCardCaption.Options.UseBorderColor = true;
            this.cardView1.Appearance.FocusedCardCaption.Options.UseForeColor = true;
            this.cardView1.Appearance.HideSelectionCardCaption.BackColor = System.Drawing.Color.Gray;
            this.cardView1.Appearance.HideSelectionCardCaption.BorderColor = System.Drawing.Color.Gray;
            this.cardView1.Appearance.HideSelectionCardCaption.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(212)))), ((int)(((byte)(208)))), ((int)(((byte)(200)))));
            this.cardView1.Appearance.HideSelectionCardCaption.Options.UseBackColor = true;
            this.cardView1.Appearance.HideSelectionCardCaption.Options.UseBorderColor = true;
            this.cardView1.Appearance.HideSelectionCardCaption.Options.UseForeColor = true;
            this.cardView1.Appearance.SelectedCardCaption.BackColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(10)))), ((int)(((byte)(10)))));
            this.cardView1.Appearance.SelectedCardCaption.ForeColor = System.Drawing.Color.White;
            this.cardView1.Appearance.SelectedCardCaption.Options.UseBackColor = true;
            this.cardView1.Appearance.SelectedCardCaption.Options.UseForeColor = true;
            this.cardView1.Appearance.SeparatorLine.BackColor = System.Drawing.Color.Transparent;
            this.cardView1.Appearance.SeparatorLine.Options.UseBackColor = true;
            this.cardView1.BorderStyle = DevExpress.XtraEditors.Controls.BorderStyles.HotFlat;
            this.cardView1.CardWidth = 230;
            this.cardView1.FocusedCardTopFieldIndex = 0;
            gridFormatRule1.Name = "Format0";
            gridFormatRule1.Rule = null;
            this.cardView1.FormatRules.Add(gridFormatRule1);
            this.cardView1.GridControl = this.gridControl1;
            this.cardView1.Name = "cardView1";
            this.cardView1.OptionsBehavior.Editable = false;
            this.cardView1.OptionsBehavior.Sizeable = false;
            this.cardView1.PaintStyleName = "Flat";
            this.cardView1.VertScrollVisibility = DevExpress.XtraGrid.Views.Base.ScrollVisibility.Auto;
            // 
            // CasesList
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.Controls.Add(this.gridControl1);
            this.Name = "CasesList";
            this.Size = new System.Drawing.Size(797, 437);
            this.Load += new System.EventHandler(this.CasesList_Load);
            ((System.ComponentModel.ISupportInitialize)(this.gridControl1)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.cardView1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private DevExpress.XtraGrid.GridControl gridControl1;
        private DevExpress.XtraGrid.Views.Card.CardView cardView1;



    }
}
